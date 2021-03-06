#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

/**
 * @class Panorama View
 * @author Robby Kraft
 * @date 8/24/13
 *
 * @availability iOS (5.0 and later)
 *
 * @discussion a dynamic GLKView with a touch and motion sensor interface to align and immerse the perspective inside an equirectangular panorama projection
 */
@interface PanoramaView : GLKView


-(id) init;  // recommended init method

-(void) draw;  // place in GLKViewController's glkView:drawInRect:

/// set image
-(void) setImage:(UIImage*)image;

/// set image by path or bundle - will check at both
-(void) setImageWithName:(NSString*)fileName;


/* orientation */

/// forward vector axis (into the screen)
@property (nonatomic, readonly) GLKVector3 lookVector;

/// forward horizontal azimuth (-π to π)
@property (nonatomic, readonly) float lookAzimuth;

/// forward vertical altitude (-.5π to .5π)
@property (nonatomic, readonly) float lookAltitude;

/// Activates accelerometer + gyro orientation
@property (nonatomic) BOOL orientToDevice;

/// Enables UIPanGestureRecognizer to affect view orientation
@property (nonatomic) BOOL touchToPan;

/**
 * Align Z coordinate axis (into the screen) to a GLKVector.
 * (due to a fixed up-vector, flipping will occur at the poles)
 *
 */
-(void) orientToVector:(GLKVector3)vector;

/**
 * Align Z coordinate axis (into the screen) to azimuth and altitude.
 * (due to a fixed up-vector, flipping will occur at the poles)
 *
 */
-(void) orientToAzimuth:(float) azimuth Altitude:(float)altitude;


/*  projection & touches  */

/// Split screen mode for use in VR headsets
@property (nonatomic) BOOL VRMode;

/// Set of (UITouch*) touches currently active
@property (nonatomic, readonly) NSSet *touches;

/// The number of active screen touches
@property (nonatomic, readonly) NSInteger numberOfTouches;

/// Field of view in DEGREES
@property (nonatomic) float fieldOfView;

/// Enables UIPinchGestureRecognizer to affect FieldOfView
@property (nonatomic) BOOL pinchToZoom;

/// Dynamic overlay of latitude and longitude intersection lines for all touches
@property (nonatomic) BOOL showTouches;

/**
 * Convert a 3D world-coordinate (specified by a vector from the origin) to a 2D on-screen coordinate
 *
 * @return a screen pixel coordinate representation of a 3D world coordinate
 */
-(CGPoint) screenLocationFromVector:(GLKVector3)vector;

/**
 * Converts a 2D on-screen coordinate to a vector in 3D space pointing out from the origin
 *
 * @return GLKVector3 vector pointing outward from origin
 */
-(GLKVector3) vectorFromScreenLocation:(CGPoint)point;

/**
 * Converts a 2D on-screen coordinate to a pixel (x,y) of the loaded panorama image
 *
 * @return CGPoint image coordinate in pixels. If no image, between 0.0 and 1.0
 */
-(CGPoint) imagePixelAtScreenLocation:(CGPoint)point;

/**
 * Hit-detection for all active touches
 *
 * @return YES if touch is inside CGRect, NO otherwise
 */
-(BOOL) touchInRect:(CGRect)rect;

@end
