//
//  RingtonePlaybackInteractorSpy.swift
//  Telephone
//
//  Copyright (c) 2008-2016 Alexey Kuznetsov
//
//  Telephone is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Telephone is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//

import UseCases

public class RingtonePlaybackInteractorSpy {
    public private(set) var didCallStartPlayingRingtone = false
    public private(set) var didCallStopPlayingRingtone = false

    public init() {}
}

extension RingtonePlaybackInteractorSpy: RingtonePlaybackInteractorInput {
    public func startPlayingRingtone() throws {
        didCallStartPlayingRingtone = true
    }

    public func stopPlayingRingtone() {
        didCallStopPlayingRingtone = true
    }
}
