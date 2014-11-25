#include "character.h"

void Character::updateInformation(float myPx, float myPy, float enPx, float enPy, int Ru){
	MyPositionX = myPx;
	MyPositionY = myPy;
	EnemyPositionX = enPx;
	EnemyPositionY = enPy;
	Runner = Ru;
}

void Character::MoveForward(int delay){ FMoveForward(delay); }
void Character::MoveBackward(int delay){ FMoveBackward(delay); }
void Character::Jump(int delay){ FJump(delay); }
void Character::Attack(){ FAttack(); }
void Character::crouch(int delay){ Fcrouch(delay);}
void Character::upSword(int delay){ FupSword(delay); }

float Character::getMyPositionX(){ return MyPositionX; }
float Character::getEnemyPositionX(){ return MyPositionY;; }
float Character::getMyPositionY(){ return EnemyPositionX; }
float Character::getEnemyPositionY(){ return EnemyPositionY; }

int Character::getRunner(){ return Runner; }

void Character::ActionThead(){}

void Character::setCommands(void(mf)(int delay), void(mb)(int delay), void(j)(int delay), void(a)(), void(c)(int delay), void(up)(int delay)){
	FMoveForward = mf;
	FMoveBackward = mb;
	FJump = j;
	FAttack = a;
	Fcrouch = c;
	FupSword = up;
}

void Character::test(){
	FMoveForward(0);
	FMoveBackward(0);
	FJump(0);
	FAttack();
	Fcrouch(0);
	FupSword(0);
}

void Character::playThread(){
	thread jj([this] { ActionThead(); });
	jj.detach();
}