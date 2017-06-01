#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Gyroscope.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    addLabels();
    
    Gyroscope::startGyroscope();
    addSprite3D();
    scheduleUpdate();
    return true;
}

void HelloWorld::addLabels(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    auto labelTitle = Label::createWithTTF("Gyroscope", "fonts/arial.ttf", 15);
    labelTitle->setPosition(visibleSize.width/2,
                            visibleSize.height - labelTitle->getContentSize().height);
    this->addChild(labelTitle);
    
    auto labelReset = Label::createWithTTF("Reset Rotation", "fonts/arial.ttf", 15);
    labelReset->setPosition(visibleSize.width/2,
                             labelTitle->getContentSize().height);
    this->addChild(labelReset);
    
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [&,labelReset](cocos2d::Touch* touch, cocos2d::Event* event)
    {
        cocos2d::Vec2 p = touch->getLocation();
        
        if(labelReset->getBoundingBox().containsPoint(p))
        {
            sprite->setRotation3D(Vec3(0,0,0));
            return true;
        }
        return false;
    };
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::addSprite3D(){
    sprite = Sprite3D::create("boss1.obj");
    sprite->setScale(10.f);
    sprite->setTexture("boss.png");
    auto s = Director::getInstance()->getWinSize();
    sprite->setPosition( Vec2(s.width/2, s.height/2));
    addChild( sprite );
}

void HelloWorld::update(float delta){
    Vec3 rate =Gyroscope::getRate();
    CCLOG("x rate: %f, y rate: %f, z rate: %f",rate.x, rate.y, rate.z);
    
    Vec3 spriteRotation = sprite->getRotation3D();
    Vec3 newRotation = Vec3(spriteRotation.x + rate.y, spriteRotation.y + rate.x, spriteRotation.z+rate.z);
    
    sprite->setRotation3D(newRotation);
}
