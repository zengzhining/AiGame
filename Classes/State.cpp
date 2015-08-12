#include "State.h"
#include "Hero.h"

void AttackState::Enter(Hero* h) {
	auto winSize = Director::getInstance()->getVisibleSize();
	h->Idle();
	log("onEvnter AttackState");
	h->getSkeleton()->flipX = 0;
	h->setPosition(winSize.width / 4, winSize.height / 2);
}

void AttackState::execute(Hero* h) {
	h->Attack();
	h->minitesHp(10);
	h->addMoney(100);
	//如果有足够的钱就停止
	if (h->haveEnoughMoney()){
		h->ChangeState(new WalkState());
		return;
	}

	//如果没有体力，就进入站立状态
	if (h->isTooTied()) {
		h->ChangeState(new IdleState());
		return;
	}

	

	
}

void AttackState::Exit(Hero* h){
	log("Exit AttackState");
}

//IdleState

void IdleState::Enter(Hero* h) {
	log("now Enter IdleState");
	auto winSize = Director::getInstance()->getVisibleSize();
	h->getSkeleton()->flipX = 0;
	h->setPositionX(winSize.width / 2);
}

void IdleState::execute(Hero* h) {
	log("now execute IdleState");
	h->Idle();
	h->addHp(5);

	if (h->isNotTired())
	{
		h->ChangeState(new AttackState());
	}
	

	
}

void IdleState::Exit(Hero* h){
	log("now Exit IdleState");
}

//Walk State
void WalkState::Enter(Hero* h) {
	log("now Enter the WalkState");
	auto winSize = Director::getInstance()->getVisibleSize();
	h->setPositionX(winSize.width * 3 / 4);
	h->getSkeleton()->flipX = 1;

}

void WalkState::execute(Hero* h) {
	log("now execute the WalkState");
	h->Walk();
	h->minitesHp(5);
	h->minitesMoney(50);
	if (h->haveNoMoney())
	{
		h->ChangeState(new AttackState());
		return;
	}
	if (h->isTooTied())
	{
		h->ChangeState(new IdleState());
		return;
	}
	
	
}

void WalkState::Exit(Hero* h) {
	log("now Exit the WalkState");
}