#include "Hero.h"
#include "State.h"


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
	initData();

	scheduleUpdate();

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
			_state = HeroState::jump;
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

void Hero::ChangeState(State* pNewState) {
	assert(m_currentState && pNewState);
	//调用现有状态的退出方法
	m_currentState->Exit(this);
	//改变状态到新的状态
	m_currentState = pNewState;
	//调用新状态的进入方法
	m_currentState->Enter(this);
}

void Hero::update(float deltaTime) {
	SkeletonAnimation::update(deltaTime);
	if (_time > 0.5)
	{
		_time = 0;
		if (m_currentState) {
			m_currentState->execute(this);
			log("hp:%d, money:%d", this->getHp(), this->getMoney());
		}
		
	}
	_time += deltaTime;
}

void Hero::minitesHp(int hp) {
	_Hp -= hp;
}

void Hero::addHp(int hp) {
	_Hp += hp;
}

void Hero::setHp(int hp) {
	_Hp = hp;
}

int Hero::getHp(){
	return _Hp;
}

bool Hero::initData(){
	_time = 0;
	_Hp = 100;
	_Money = 0;
	m_currentState = new AttackState();
	return true;
}

void Hero::addMoney(int money) {
	_Money += money;
}
void Hero::minitesMoney(int money) {
	_Money -= money;
}

int Hero::getMoney(){
	return _Money;
}

bool Hero::haveEnoughMoney(){
	if (this->getMoney() >= 1000)
	{
		return true;
	}

	return false;
}

bool Hero::haveNoMoney(){
	if (this->getMoney() <= 50)
	{
		return true;
	}

	return false;
}

bool Hero::isTooTied(){
	if (this->getHp() <= 20) {
		return true;
	}
	return false;
}

bool Hero::isNotTired(){
	if (this->getHp() >= 80)
	{
		return true;
	}

	return false;
}