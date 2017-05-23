#include "Gyroscope.h"

//@import CoreMotion;
#import <CoreMotion/CMDeviceMotion.h>
#import <CoreMotion/CMMotionManager.h>

CMMotionManager *motionManager;


void Gyroscope::startGyroscope()
{
    motionManager = [[CMMotionManager alloc] init];
    [motionManager startDeviceMotionUpdates];
}

cocos2d::Vec2 Gyroscope::getData()
{    
    CMDeviceMotion *deviceMotion = motionManager.deviceMotion;
    
    if(deviceMotion == nil)
        return cocos2d::Vec2(0, 0);
    
    // Get device rotation
    CMRotationRate rotationRate = deviceMotion.rotationRate;
    return cocos2d::Vec2(rotationRate.y, rotationRate.x);
}

void Gyroscope::stopGyroscope()
{
    [motionManager stopDeviceMotionUpdates];
    motionManager = nil;
}
