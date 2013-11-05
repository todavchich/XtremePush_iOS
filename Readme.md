XTremePush guide
==================

### Introduction


[Download](https://github.com/xtremepush/XtremePush_iOS/archive/master.zip) the latest library version. The archive should contain next files:

* XPush.a: The required library
* XPush.h: The required header file containing methods declarations for using XPush library
* Readme.md: The file containing instructions how to use XPush library

### Installation

1. In Finder drag XPush/ into project's folder
2. Add files to your project: Files -> Add files to "ProjectName"
3. Add next frameworks to your target:
	* CoreLocation
	* SystemConfiguration
	* MobileCoreServices
	* CoreTelephony
	* CFNetwork
	* libz.dlib
4. In your Info.plist file add "XtremePushApplicationKey" in key field and your application key in value field.
5. In your Info.plist file add "XtremePushSandoxMode" in key field and set it to YES if you want to use APNS in "sandbox" mode.
6. In your Application Delegate: import XPush and inside `applicationDidFinishLaunching:withOptions:` add next code:
7. Make sure you select the same Provisioning profile which is associated with the p12 you uploaded on the dashboard.

```objc
// Uncomment next line to use sendbox mode
// [XPush setSandboxModeOn:YES];
[XPush registerForRemoteNotificationTypes:UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeSound | UIRemoteNotificationTypeBadge];
[XPush applicationDidFinishLaunchingWithOptions:launchOptions];
```

and call corresponding remote notifications handling methods in Application delegate

```objc
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
  [XPush applicationDidRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
	[XPush applicationDidReceiveRemoteNotification:userInfo];
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
	[XPush applicationDidFailToRegisterForRemoteNotificationsWithError:error];

```

### Methods description

* Library info

```objc
// returns version of XPush library
+ (NSString *)version;
// returns device token for Apple push notifications and XPush device identifier
+ (NSDictionary *)deviceInfo;
```

* Setting up library

```objc
// returns `YES` if library using sendbox environment for push notifications
+ (BOOL)isSandboxModeOn;
// Setting application badge number wiping
+ (void)setShouldWipeBadgeNumber:(BOOL)shouldWipeBadgeNumber;
// Returns YES if badge number is wiped on app loading
+ (BOOL)shouldWipeBadgeNumber;
// Registering for notifications methods
+ (void)registerForRemoteNotificationTypes:(UIRemoteNotificationType)types;
+ (void)unregisterForRemoteNotifications;
```

* Service methods

```objc
// send tag to server
+ (void)hitTag:(NSString *)tag;
// load list of push notifications with specific offset and limit
+ (void)getPushNotificationsOffset:(NSUInteger)offset limit:(NSUInteger)limit completion:(void(^)(NSArray *pushList, NSError *error))completion;
// present controller with list of pushes
+ (void)showPushListController;
```

* System methods

```objc
// Call these mehtods in corresponding methods of Application Delegate
+ (void)applicationDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
+ (void)applicationDidRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
+ (void)applicationDidReceiveRemoteNotification:(NSDictionary *)userInfo;
+ (void)applicationDidFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
```