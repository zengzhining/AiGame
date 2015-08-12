#include "FSMScene.h"
#include "Army001.h"
#include "Hero.h"
USING_NS_CC;

Scene* FSMScene::createScene(){
	auto scene = Scene::create();

	auto layer = FSMScene::create();

	scene->addChild(layer);

	return scene;
}

bool FSMScene::init(){
	
	initData();
	initView();


	return true;
}

bool FSMScene::initData(){
	winSize = Director::getInstance()->getVisibleSize();
	_eveDispatcher = Director::getInstance()->getEventDispatcher();
	_hero = Hero::create();
	_army = Army001::create();

	

	return true;
}

bool FSMScene::initView(){
	_hero->setPosition(winSize.width / 4, winSize.height / 2);
	addChild(_hero);

	//add Army
	_army->setPosition(winSize.width * 3 / 4, winSize.height / 2);
	addChild(_army);

	//scheduleUpdate();
	return true;


}

void FSMScene::update(float delta) {
	
}