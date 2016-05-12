//
//  PeakSDK.h
//  PeakSDK v.1.0.0
//
//  Copyright © 2016 Peak. All rights reserved.
//

/**
 * Use the PeakSDKDelegate to receive callbacks on:
 * - Success or failure to initialize SDK;
 * - Success or failure to show a banner or interstitial;
 * - Interstitials closing;
 * - Rewarded interstitials granting users a reward for completing the rewarded experience.
 */
@protocol PeakSDKDelegate<NSObject>
@optional

/** @name Initialization success */

/**
 * Notifies your app that initialization has succeeded.
 */
- (void)didCompleteInitialization;

/**
 * Notifies your app that initialization has failured.
 * @param error The error object. It can contain underlying error with more useful information for key NSUnderlyingErrorKey.
 */
- (void)didFailInitializationWithError:(NSError *)error;

/**
 * Notifies your app that a banner was successfully shown.
 */
- (void)didShowBanner;

/**
 * Notifies your app that showing of a banner was failed.
 * @param error The error object. It can contain underlying error with more useful information for key NSUnderlyingErrorKey
 */
- (void)didFailToShowBannerWithError:(NSError *)error;

/**
 * Notifies your app that an interstitial ad will actually play.
 * This method is called when PeakSDK has taken control of the device screen and is about to begin showing an interstitial ad.
 */
- (void)didShowInterstitial;

/**
 * Notifies your app that showing of an interstitial ad was failed.
 * @param error The error object. It can contain underlying error with more useful information for key NSUnderlyingErrorKey
 */
- (void)didFailToShowInterstitialWithError:(NSError *)error;

/**
 * Notifies your app that an interstitial ad completed playing and control has been returned to the app.
 */
- (void)didCloseInterstitial;

/**
 * Notifies your app that rewarded interstitials granting users a reward for completing the rewarded experience.
 */
- (void)didCompleteRewardExperience;

@end

/** PeakSDK it's a client SDK for integration with the Peak Mediation Platform. */
@interface PeakSDK : NSObject

/*
 * Delegate object of PeakSDK
 * @param delegate (*optional*) The delegate to receive SDK events. Can be `nil` for apps that do not need these events.
 */
@property(weak, nonatomic) id<PeakSDKDelegate> delegate;

/*
 * Returns the singleton PeakSDK.
 */
+ (instancetype)sharedInstance;

/**
 * Configures PeakSDK for your app; required for usage of the rest of the API.
 * PeakSDK does not begin preparing ads for display or performing reporting until after it is configured by your app.
 * @param appId The PeakSDK app ID for your app.
 */
- (void)configureWithAppId:(NSString *)appId;

/**
 * Checks that PeakSDK can show ad for zone.
 * @param zone An NSString representing the ad's zone ID.
 */
- (BOOL)canShowAdForZone:(NSString *)zone;

/**
 * Shows banner in view for specified zone.
 * @param view UIView object which will show banner in his frame
 * @param zone An NSString representing the ad's zone ID.
 */
- (void)showBannerInView:(UIView *)view forZone:(NSString *)zone;

/**
 * Shows interstitial ad specified zone.
 * @param zone An NSString representing the ad's zone ID.
 */
- (void)showInterstitialForZone:(NSString *)zone;

@end
