#ifndef __HERO__
#define __HERO__

#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>
#include "spine/spine.h"

using namespace spine;


USING_NS_CC;

class Hero : public SkeletonAnimation {

public:
	enum HeroState
	{
		idle,walk,attack,jump,

	};

	static Hero* create();

	virtual bool init();

	virtual void setAllEvent();

	//idle
	virtual void Idle();

	//walk
	virtual void Walk();

	//attack
	virtual void Attack();

	//jump
	virtual void Jump();

	int getState();

	Hero() :SkeletonAnimation("skeleton.json", "skeleton.atlas", 0.8){

	}



private:
	int _state;
	

};
#endif //__HERO__