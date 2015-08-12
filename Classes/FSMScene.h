#ifndef __FSMSCENE____

#define __FSMSCENE____

#include "cocos2d.h"

class Hero;
class Army001;

USING_NS_CC;

class FSMScene : Layer
{
public:
	static Scene* createScene();

	CREATE_FUNC(FSMScene);

	bool init();

	bool initData();
	bool initView();

	void update(float delta);

public:


protected:
private:
	Size winSize;

	EventDispatcher* _eveDispatcher;
	Hero* _hero;
	Army001* _army;

};

#endif // !__FSMSCENE____
