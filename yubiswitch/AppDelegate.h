//  AppDelegate.h
//  yubiswitch

/*
 yubiswitch - enable/disable yubikey
 Copyright (C) 2013-2015  Angelo "pallotron" Failla <pallotron@freaknet.org>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#import <Cocoa/Cocoa.h>
#import <Carbon/Carbon.h>

#import "YubiKey.h"
#import "AboutWindowController.h"
#import "PreferencesController.h"
#import "ComputerStateMonitor.h"

@interface AppDelegate : NSObject <NSApplicationDelegate> {
    IBOutlet NSMenu* statusMenu;
    NSStatusItem* statusItem;
    bool isEnabled;
    YubiKey* yk;
    NSTimer *m_timer;
    NSUserNotification* usernotification;
    AboutWindowController* aboutwc;
    PreferencesController* prefwc;
    NSTimer* reDisableTimer;
    ComputerStateMonitor* state_monitor;
}

@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSUserDefaultsController *controller;

-(IBAction)toggleSwitchOffDelay:(id)sender;
-(IBAction)toggleLockWhenUnplugged:(id)sender;
-(IBAction)toggleDisplayNotications:(id)sender;
-(IBAction)toggle:(id)sender;
-(IBAction)quit:(id)sender;
-(IBAction)about:(id)sender;
-(IBAction)pref:(id)sender;
-(IBAction)toggleDisableSleepLock:(id)sender;
-(void)enableYubiKey:(BOOL)enable;
-(void)notify:(NSString *)msg;
-(void)reDisableYK;
-(NSTimer*)createTimer:(NSInteger)interval;
-(void)lockComputer;
-(bool)application:(NSApplication *)sender delegateHandlesKey:(NSString *)key;
-(bool)status;

@end
