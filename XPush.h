//
//  XPush.h
//  XtremePush
//
//  Created by Andrew Kopanev on 3/10/13.
//  Copyright (c) 2013 Andrew Kopanev. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface XPush : NSObject

+ (BOOL)isSandboxModeOn;

+ (void)setShouldWipeBadgeNumber:(BOOL)shouldWipeBadgeNumber;
+ (BOOL)shouldWipeBadgeNumber;

+ (void)registerForRemoteNotificationTypes:(UIRemoteNotificationType)types;
+ (void)unregisterForRemoteNotifications;

+ (void)applicationDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
+ (void)applicationDidRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
+ (void)applicationDidReceiveRemoteNotification:(NSDictionary *)userInfo;
+ (void)applicationDidFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

+ (NSString *)version;

+ (void)hitTag:(NSString *)tag;

@end
