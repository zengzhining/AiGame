#ifndef __STATE___

#define  __STATE___
class Hero;
class State {

public:
	State(){}

	virtual ~State(){}

	virtual void Enter(Hero* h) = 0;
	virtual void execute(Hero* h) = 0;
	virtual void Exit(Hero* h) = 0;
};

//¹¥»÷×´Ì¬£¬Ôö¼Ó¼¢¿Ê¶È
class AttackState : public State {

public:

	virtual void Enter(Hero* h);

	virtual void execute(Hero* h);

	virtual void Exit(Hero* h);


};

class IdleState : public State {

public:

	virtual void Enter(Hero* h);

	virtual void execute(Hero* h);

	virtual void Exit(Hero* h);
};

class WalkState : public State {

public:
	virtual void Enter(Hero* h);

	virtual void execute(Hero* h);

	virtual void Exit(Hero* h);
};


#endif // !__STATE___
