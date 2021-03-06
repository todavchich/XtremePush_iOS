XTremePush guide
==================

### Introduction


[Download](https://github.com/xtremepush/XtremePush_iOS/archive/master.zip) the latest library version. The archive should contain the following files:

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
4. In your Info.plist file add "XtremePushApplicationKey" in key field and your application key in value field. **You can find the "XtremePushApplicationKey" in the Settings (General Settings) page of your app under 'App Key'.**
5. In your Info.plist file add "XtremePushSandoxMode" in key field and set it to YES if you want to use APNS in "Sandbox" gateway. **NOTE: Sandbox Mode is only used for DEBUG builds compiled with development mobile provisioning profile! For Ad Hoc and App Store builds, please, make sure to turn Sandbox Mode off by setting the value to NO or removing the key.**
6. Make sure you select the same Provisioning profile which is associated with the p12 you uploaded on the settings page of your app on dashboard.
7. In your Application Delegate: import XPush and inside `applicationDidFinishLaunching:withOptions:` add the following code:

```objc

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
}
```

### Methods description

* Library info

```objc
// returns version of XPush library
+ (NSString *)version;
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

* System methods

```objc
// Call these mehtods in corresponding methods of Application Delegate
+ (void)applicationDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
+ (void)applicationDidRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
+ (void)applicationDidReceiveRemoteNotification:(NSDictionary *)userInfo;
+ (void)applicationDidFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
```

* Tag methods

```objc
// Send tags to server to track events
+ (void)hitTag:(NSString *)tag;
```