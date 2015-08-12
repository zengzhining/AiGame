#include "HelloWorldScene.h"

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	hero = Hero::create();
	hero->setPosition(visibleSize.width / 4, visibleSize.height / 2);
	addChild(hero);
	hero->Idle();

	army = Army001::create();
	army->setPosition(visibleSize.width * 3 / 4, visibleSize.height / 2);
	army->Walk();
	addChild(army);
	distan = 30;

	scheduleUpdate();

    
    return true;
}

void HelloWorld::update(float delta) {
	log("update~~~~~");
	auto positionHero = hero->getPosition();
	auto positionArmy = army->getPosition();

	if (positionArmy.x - positionHero.x <= 50)
	{
		army->Idle();
		hero->Attack();
	}
	else {
		army->setPositionX(army->getPositionX() - 2);
	}
}



