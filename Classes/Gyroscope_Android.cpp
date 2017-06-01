#include "Gyroscope.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "platform/android/jni/JniHelper.h"

#define  CLASS_NAME "com/ecantalejos/cpp/Gyroscope"


void Gyroscope::startGyroscope()
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "startGyroscope", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

cocos2d::Vec2 Gyroscope::getRate()
{
    jfloat valuex;
    jfloat valuey;
    jfloat valuez;
    //datax
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "getDataX", "()F")) {
        valuex = t.env->CallStaticFloatMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
    
    //datay
    if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "getDataY", "()F")) {
        valuey = t.env->CallStaticFloatMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
    
    //dataz
    if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "getDataZ", "()F")) {
        valuez = t.env->CallStaticFloatMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
    return cocos2d::Vec3(valuex,valuey,valuez);
}

void Gyroscope::stopGyroscope()
{
    cocos2d::JniMethodInfo t;
    if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, "stopGyroscope", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

#endif

