#ifndef __HERO__
#define __HERO__

#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>
#include "spine/spine.h"

using namespace spine;

class State;


USING_NS_CC;

class Hero : public SkeletonAnimation {

public:
	enum HeroState
	{
		idle,walk,attack,jump,

	};

	static Hero* create();

	virtual bool init();

	bool initData();

	virtual void setAllEvent();

	//idle
	virtual void Idle();

	//walk
	virtual void Walk();

	//attack
	virtual void Attack();

	//jump
	virtual void Jump();

	void minitesHp(int hp);

	void addHp(int hp);

	void setHp(int hp);

	int getHp();

	void update(float deltaTime);

	int getState();

	void ChangeState(State* pNewState);

	Hero() :SkeletonAnimation("skeleton.json", "skeleton.atlas", 0.8){

	}

	State* m_currentState;

	void addMoney(int money);

	void minitesMoney(int money);

	int getMoney();

	//�Ƿ���Ǯ
	bool haveEnoughMoney();
	//�Ƿ�ûǮ
	bool haveNoMoney();

	//�Ƿ�̫ƣ��
	bool isTooTied();
	//�Ƿ�ƣ��
	bool isNotTired();
private:
	int _state;

	float _time;

	int _Hp;
	int _Money;
	int _mLocation;
	

};
#endif //__HERO__