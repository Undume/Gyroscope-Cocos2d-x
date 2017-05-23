
#ifndef __Gyroscope__
#define __Gyroscope__

#include "cocos2d.h"


class CC_DLL Gyroscope
{
public:
    static void startGyroscope();
    static cocos2d::Vec2 getData();
    static void stopGyroscope();
};

#endif
