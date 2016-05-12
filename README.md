PeakSDK
=======

## Discussion

TBD

## Integration Instructions

### Install CocoaPods

[CocoaPods: The Objective-C Library Manager](http://www.cocoapods.org) allows you to manage the library dependencies of your iOS Xcode project. You can install the CocoaPods tool on OS X by running the following command from the terminal. Detailed information is available in the [Getting Started guide](https://guides.cocoapods.org/using/getting-started.html#getting-started).

	$ sudo gem install cocoapods

### Add a PeakSDK to your iOS app

CocoaPods is used to install and manage dependencies in existing Xcode projects.

1. Create an Xcode project, and save it to your local machine.
2. Create a file named Podfile in your project directory. This file defines your project's dependencies, and is commonly referred to as a Podspec.
3. Open Podfile, and add your dependencies. A simple Podspec is shown here:

		source 'https://shahmin@bitbucket.org/nixpeak/peaksdk
		platform :ios, '7.0'
		pod 'PeakSDK'

4. Save the file.
5. Open a terminal and cd to the directory containing the Podfile.

		$ cd <path-to-project>/project/

6. Run the pod install command. This will install the SDKs specified in the Podspec, along with any dependencies they may have.

		$ pod install

7. Open your app's .xcworkspace file to launch Xcode. Use this file for all development on your app.

### Disabling ATS

App Transport Security (ATS) requires apps to make secure network connections via SSL and enforces HTTPS connections through its requirements on the SSL version, encryption cipher, and key length. At this time, however, we require that publishers disable ATS for PeakSDK. This can be done two ways; please see below.

**Option 1**

The easiest way to turn off ATS for AdColony is to disable it for the entire application by adding the following entry to the app's plist:

	<key>NSAppTransportSecurity</key>
	<dict>
	    <key>NSAllowsArbitraryLoads</key>
	    <true/>
	</dict>

**Option 2**

Disabling ATS for PeakSDK does not require that it be turned off for the entire application, however. In an effort to be aligned with Apple's recommendations around ATS, publishers may want to ensure their apps are as ATS-compliant as they can be. If you are one of those publishers, then Option 2 is what you want. To disable ATS for PeakSDK but keep it enabled for other domains, simply add the XML from Option 1 to your app's plist (which disables ATS for the entire application), and then add an exception for each domain known to be ATS-compliant. Please refer to the example below.

	<key>NSAppTransportSecurity</key>
	<dict>
	    <key>NSAllowsArbitraryLoads</key>
	    <true/>
	    <key>NSExceptionDomains</key>
	    <dict>
	        <key>example.com</key>
	        <dict>
	            <key>NSIncludesSubdomains</key>
	            <true/>
	        </dict>
	    </dict>
	</dict>

### Using canOpenURL:

Apple has also restricted usage of the `canOpenURL:` API, which PeakSDK uses to make decisions about whether or not we can land users in certain apps from our Dynamic End Cards (DECs). For example, one of our ad units could be for a new movie, and the associated DEC may present functionality to the user that allows them to send a tweet about it using the Twitter app. This kind of functionality is still possible in iOS 9, but publishers must enable it for the applications PeakSDK links to by authorizing each app’s URL scheme in their plist. Note that if the schemes are not added, users will be taken to the app’s website instead, which may result in an undesirable user experience - having to login to the site, for example. In order to enable deep-linking for the apps the PeakSDK uses, please add the following entry to your apps plist:

	<key>LSApplicationQueriesSchemes</key>
	    <array>
	        <string>fb</string>
	        <string>instagram</string>
	        <string>tumblr</string>
	        <string>twitter</string>
	    </array>
	</key>

### Using PeakSDK

1. Import PeakSDK in your source files:

        #import <PeakSDK/PeakSDK.h>

2. Initialize SDK with your AppID:

        [[PeakSDK sharedInstance] configureWithAppId:@"YOUR_APP_ID"];

3. Check availability of ad:

        BOOL canShow = [[PeakSDK sharedInstance] canShowAdForZone:@"YOUR_ZONE_ID"];

4. Show insterstitial ad (for example by button click):

        [[PeakSDK sharedInstance] showInterstitialForZone:@"YOUR_ZONE_ID"];

5. Show banner in any UIView object:

        [[PeakSDK sharedInstance] showBannerInView:view forZone:@"YOUR_ZONE_ID"];

6. Handle SDK events using delegate pattern:

        [[PeakSDK sharedInstance] setDelegate:self];
