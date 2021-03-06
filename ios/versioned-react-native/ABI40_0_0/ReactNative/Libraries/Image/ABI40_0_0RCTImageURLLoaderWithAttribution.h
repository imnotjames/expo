/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <ABI40_0_0React/ABI40_0_0RCTImageURLLoader.h>

// TODO (T61325135): Remove C++ checks
#ifdef __cplusplus
namespace ABI40_0_0facebook {
namespace ABI40_0_0React {

struct ImageURLLoaderAttribution {
  int32_t nativeViewTag = 0;
  int32_t surfaceId = 0;
};

} // namespace ABI40_0_0React
} // namespace ABI40_0_0facebook
#endif

@interface ABI40_0_0RCTImageURLLoaderRequest : NSObject

@property (nonatomic, strong, readonly) NSString *requestId;
@property (nonatomic, strong, readonly) NSURL *imageURL;
@property (nonatomic, copy, readonly) ABI40_0_0RCTImageLoaderCancellationBlock cancellationBlock;

- (instancetype)initWithRequestId:(NSString *)requestId imageURL:(NSURL *)imageURL cancellationBlock:(ABI40_0_0RCTImageLoaderCancellationBlock)cancellationBlock;
- (void)cancel;

@end

/**
 * Same as the ABI40_0_0RCTImageURLLoader interface, but allows passing in optional `attribution` information.
 * This is useful for per-app logging and other instrumentation.
 */
@protocol ABI40_0_0RCTImageURLLoaderWithAttribution <ABI40_0_0RCTImageURLLoader>

// TODO (T61325135): Remove C++ checks
#ifdef __cplusplus
/**
 * Same as the ABI40_0_0RCTImageURLLoader variant above, but allows optional `attribution` information.
 * Caller may also specify a preferred requestId for tracking purpose.
 */
- (ABI40_0_0RCTImageURLLoaderRequest *)loadImageForURL:(NSURL *)imageURL
                                         size:(CGSize)size
                                        scale:(CGFloat)scale
                                   resizeMode:(ABI40_0_0RCTResizeMode)resizeMode
                                    requestId:(NSString *)requestId
                                  attribution:(const ABI40_0_0facebook::ABI40_0_0React::ImageURLLoaderAttribution &)attribution
                              progressHandler:(ABI40_0_0RCTImageLoaderProgressBlock)progressHandler
                           partialLoadHandler:(ABI40_0_0RCTImageLoaderPartialLoadBlock)partialLoadHandler
                            completionHandler:(ABI40_0_0RCTImageLoaderCompletionBlock)completionHandler;
#endif

/**
 * Image instrumentation - notify that the image content (UIImage) has been set on the native view.
 */
- (void)trackURLImageContentDidSetForRequest:(ABI40_0_0RCTImageURLLoaderRequest *)loaderRequest;

/**
 * Image instrumentation - start tracking the on-screen visibility of the native image view.
 */
- (void)trackURLImageVisibilityForRequest:(ABI40_0_0RCTImageURLLoaderRequest *)loaderRequest imageView:(UIView *)imageView;

/**
 * Image instrumentation - notify that the native image view was destroyed.
 */
- (void)trackURLImageDidDestroy:(ABI40_0_0RCTImageURLLoaderRequest *)loaderRequest;

@end
