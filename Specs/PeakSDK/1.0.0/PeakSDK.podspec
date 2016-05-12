Pod::Spec.new do |s|
s.name = 'PeakSDK'
s.version = '1.0.0'
s.summary = 'PeakSDK is a framework.'
s.homepage = 'https://example.com'
s.license = 'PeakSDK'
s.authors = { 'Firstname Lastname' => 'mail@mail.com' }
s.source = { :git => 'git@bitbucket.org:nixpeak/peaksdk.git' }
s.requires_arc = true
s.platform = :ios, '7.0'
s.vendored_frameworks = 'Specs/PeakSDK/1.0.0/PeakSDK.framework'
s.resources = 'Specs/PeakSDK/1.0.0/UnityAds.bundle', 'Specs/PeakSDK/1.0.0/PeakBundle.bundle'
s.libraries = 'z'
s.frameworks = 'AdSupport', 'AudioToolbox', 'AVFoundation', 'CFNetwork', 'CoreFoundation', 'CoreGraphics', 'CoreLocation', 'CoreMedia', 'CoreTelephony', 'EventKit', 'MediaPlayer', 'MessageUI', 'MobileCoreServices', 'Security', 'Social', 'StoreKit', 'SystemConfiguration', 'UIKit', 'QuartzCore', 'WebKit'
end
