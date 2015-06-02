// Generated by Apple Swift version 1.2 (swiftlang-602.0.49.3 clang-clang-602.0.49)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
#if __has_feature(nullability)
#  define SWIFT_NULLABILITY(X) X
#else
# if !defined(__nonnull)
#  define __nonnull
# endif
# if !defined(__nullable)
#  define __nullable
# endif
# if !defined(__null_unspecified)
#  define __null_unspecified
# endif
#  define SWIFT_NULLABILITY(X)
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation.NSURLSession;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSData;


/// Represents the set of allowed device metadata.
SWIFT_PROTOCOL("_TtP12AeroGearPush25AGClientDeviceInformation_")
@protocol AGClientDeviceInformation

/// The Device Token which identifies the device within APNs.
@property (nonatomic) NSData * __nullable deviceToken;

/// The ID of the mobile Variant, for which this client will be registered.
@property (nonatomic, copy) NSString * __nullable variantID;

/// The mobile Variant's secret.
@property (nonatomic, copy) NSString * __nullable variantSecret;

/// Application specific alias to identify users with the system.
/// E.g. email address or username
@property (nonatomic, copy) NSString * __nullable alias;

/// Some categories, used for tagging the device (metadata)
@property (nonatomic, copy) NSArray * __nullable categories;

/// The name of the underlying OS (e.g. iOS)
@property (nonatomic, copy) NSString * __nullable operatingSystem;

/// The version of the used OS (e.g. 6.1.3)
@property (nonatomic, copy) NSString * __nullable osVersion;

/// The device type (e.g. iPhone or iPod)
@property (nonatomic, copy) NSString * __nullable deviceType;
@end

@class NSURL;
@class NSError;
@class NSURLSession;
@class NSURLSessionTask;
@class NSHTTPURLResponse;
@class NSURLRequest;


/// Utility to register an iOS device with the AeroGear UnifiedPush Server.
SWIFT_CLASS("_TtC12AeroGearPush20AGDeviceRegistration")
@interface AGDeviceRegistration : NSObject <NSURLSessionTaskDelegate>

/// <ul><li><p>An initializer method to instantiate an AGDeviceRegistration object.</p></li><li></li><li><p>@param serverURL the URL of the AeroGear Push server.</p></li><li></li><li><p>@return the AGDeviceRegistration object.</p></li></ul>
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithServerURL:(NSURL * __nonnull)serverURL OBJC_DESIGNATED_INITIALIZER;

/// <ul><li><p>An initializer method to instantiate an AGDeviceRegistration object.</p></li><li></li><li><p>@return the AGDeviceRegistration object.</p></li></ul>
- (SWIFT_NULLABILITY(nonnull) instancetype)init OBJC_DESIGNATED_INITIALIZER;

/// <ul><li><p>Registers your mobile device to the AeroGear Push server so it can start receiving messages. </p></li><li><p>Registration information can be provided within clientInfo block or by providin a plist file </p></li><li><p>containing the require registration information as below:</p></li><li><p><plist version="1.0"></p></li><li><p><dict></p></li><li><p><key>serverURL</key></p></li><li><p><string>pushServerURL e.g http(s)//host:port/context</string></p></li><li><p><key>variantID</key></p></li><li><p><string>variantID e.g. 1234456-234320</string></p></li><li><p><key>variantSecret</key></p></li><li><p><string>variantSecret e.g. 1234456-234320</string></p></li><li><p>...</p></li><li><p></dict></p></li><li><p></plist></p></li><li></li><li><p>@param clientInfo A block object which passes in an implementation of the AGClientDeviceInformation protocol that</p></li><li><p>holds configuration metadata that would be posted to the server during the registration process.</p></li><li></li><li><p>@param success A block object to be executed when the registration operation finishes successfully.</p></li><li><p>This block has no return value.</p></li><li></li><li><p>@param failure A block object to be executed when the registration operation finishes unsuccessfully.</p></li><li><p>This block has no return value and takes one argument: The <code>NSError</code> object describing</p></li><li><p>the error that occurred during the registration process.</p></li><li></li></ul>
- (void)registerWithClientInfo:(void (^ __null_unspecified)(id <AGClientDeviceInformation> __nonnull))clientInfo success:(void (^ __null_unspecified)(void))success failure:(void (^ __null_unspecified)(NSError * __nonnull))failure;
- (void)URLSession:(NSURLSession * __nonnull)session task:(NSURLSessionTask * __nonnull)task willPerformHTTPRedirection:(NSHTTPURLResponse * __nonnull)redirectResponse newRequest:(NSURLRequest * __nonnull)redirectReq completionHandler:(void (^ __nonnull)(NSURLRequest * __null_unspecified))completionHandler;
@end

#pragma clang diagnostic pop
