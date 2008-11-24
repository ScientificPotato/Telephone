//
//  AKTelephoneCall.h
//  Telephone
//
//  Copyright (c) 2008 Alexei Kuznetsov. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//  1. Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//  3. The name of the author may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY ALEXEI KUZNETSOV "AS IS" AND ANY EXPRESS
//  OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
//  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
//  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
//  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
//  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
//  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#import <Foundation/Foundation.h>
#import <pjsua-lib/pjsua.h>


extern const NSInteger AKTelephoneCallsMax;

@class AKTelephoneAccount, AKSIPURI;

@interface AKTelephoneCall : NSObject {
@private
	id delegate;
	
	NSInteger identifier;
	AKSIPURI *localURI;
	AKSIPURI *remoteURI;
	NSInteger lastStatus;
	NSString *lastStatusText;
	
	// Account the call belongs to
	AKTelephoneAccount *account;
}

@property(readwrite, assign) id delegate;
@property(readwrite, assign) NSInteger identifier;
@property(readwrite, retain) AKSIPURI *localURI;
@property(readwrite, retain) AKSIPURI *remoteURI;
@property(readonly, assign) NSInteger state;
@property(readonly, copy) NSString *stateText;
@property(readwrite, assign) NSInteger lastStatus;
@property(readwrite, copy) NSString *lastStatusText;
@property(readonly, assign, getter=isActive) BOOL active;
@property(readwrite, assign) AKTelephoneAccount *account;

// Designated initializer
- (id)initWithTelephoneAccount:(AKTelephoneAccount *)anAccount
					identifier:(NSInteger)anIdentifier;

- (void)answer;
- (void)hangUp;
- (void)ringbackStart;
- (void)ringbackStop;
- (void)sendDTMFDigits:(NSString *)digits;

@end

// Callbacks from PJSUA
void AKIncomingCallReceived(pjsua_acc_id, pjsua_call_id, pjsip_rx_data *);
void AKCallStateChanged(pjsua_call_id, pjsip_event *);
void AKCallMediaStateChanged(pjsua_call_id);


// Notifications.

// Calling. After INVITE is sent.
extern NSString * const AKTelephoneCallCallingNotification;

// Incoming. After INVITE is received. Delegate is not subscribed to this notification.
extern NSString * const AKTelephoneCallIncomingNotification;

// Early. After response with To tag.
extern NSString * const AKTelephoneCallEarlyNotification;	// @"AKTelephoneCallState", @"AKSIPEventCode", @"AKSIPEventReason".

// Connecting. After 2xx is sent/received.
extern NSString * const AKTelephoneCallConnectingNotification;

// Confirmed. After ACK is sent/received.
extern NSString * const AKTelephoneCallDidConfirmNotification;

// Disconnected. Session is terminated.
extern NSString * const AKTelephoneCallDidDisconnectNotification;
