#include "Hero.h"


using namespace spine;
USING_NS_CC;

Hero* Hero::create(){
	auto hero = new Hero();
	
	if (hero->init())
	{
		return hero;
	}
	return false;
}

bool Hero::init(){
	this->setMix("idle", "walk", 0.2);
	this->setMix("idle", "attack", 0.2);
	this->setAllEvent();

	return true;
	
}

void Hero::setAllEvent(){
	this->setEventListener([this](int trackIndex, spEvent* event){
		if (trackIndex != 1) {
			return;
		}
		if (event->data->intValue == 3) {
			_state = HeroState::attack;
		}
		if (event->data->intValue == 4) {
			_state = HeroState::walk;
		}
	}
	);
}
void Hero::Idle(){
	if (_state != HeroState::idle) {
		this->setAnimation(0, "idle", true);
		_state = HeroState::idle;
	}
	
}

void Hero::Walk(){
	if (_state != HeroState::walk) {
		this->setAnimation(0, "walk", true);
		_state = HeroState::walk;
	}
	

}

void Hero::Attack(){
	if (_state != HeroState::attack) {
		this->setAnimation(1, "attack", false);
		_state = HeroState::attack;
	}
	
	
}

void Hero::Jump(){
	if (_state != HeroState::jump) {
		this->setAnimation(0, "jump", false);
		_state = HeroState::jump;
	}
	
}

int Hero::getState(){
	return _state;
}