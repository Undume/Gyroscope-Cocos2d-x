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

cocos2d::Vec3 Gyroscope::getRate()
{    
    CMDeviceMotion *deviceMotion = motionManager.deviceMotion;
    
    if(deviceMotion == nil)
        return cocos2d::Vec3(0, 0, 0);
    
    // Get device rotation
    CMRotationRate rotationRate = deviceMotion.rotationRate;
    return cocos2d::Vec3(rotationRate.x, rotationRate.y, rotationRate.z);
}

void Gyroscope::stopGyroscope()
{
    [motionManager stopDeviceMotionUpdates];
    motionManager = nil;
}
