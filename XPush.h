//
//  XPush.h
//  XtremePush
//
//  Created by Xtremepush on 3/10/13.
//  Copyright (c) 2013 Xtremepush. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString *const XPushDeviceRegistrationNotification;

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
+ (NSDictionary *)deviceInfo;

+ (void)hitTag:(NSString *)tag;
+ (void)getPushNotificationsFromDate:(NSDate *)date completion:(void(^)(NSArray *pushList, NSError *error))completion;
+ (void)showPushListController;

@end


@interface XPPushModel : NSObject

@property (nonatomic, readonly) NSDate      *createDate;
@property (nonatomic, readonly) NSString    *pushId;
@property (nonatomic, readonly) NSString    *locationId;
@property (nonatomic, readonly) NSString    *alert;
@property (nonatomic, readonly) NSInteger   badge;
@property (nonatomic, readonly) NSString    *messageId;
@property (nonatomic, readonly) NSString    *url;
@property (nonatomic, readonly) BOOL        shouldOpenInApp;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end


