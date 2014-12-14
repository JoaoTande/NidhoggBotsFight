#include "character.h"

void Character::updateInformation(float myPx, float myPy, float enPx, float enPy, int Ru){
	MyPositionX = myPx;
	MyPositionY = myPy;
	EnemyPositionX = enPx;
	EnemyPositionY = enPy;
	Runner = Ru;
}

void Character::MoveForward(int delay){ 
	while (flagFreeHorizontal == 1){}// wait MoveBackward is done.
	flagFreeHorizontal = 1;//Lock create another thread like this one.
	thread Mf1(FMoveForward, delay, &flagFreeHorizontal);
	Mf1.detach();
}

void Character::MoveForward(){
	int delay = 1000;
	while (flagFreeHorizontal == 1){}// wait MoveBackward is done.
	flagFreeHorizontal = 1;//Lock create another thread like this one.
	thread Mf1(FMoveForward, delay, &flagFreeHorizontal);
	Mf1.detach();
}

void Character::MoveBackward(int delay){
	while (flagFreeHorizontal == 1){}// wait MoveForward is done.
	flagFreeHorizontal = 1;//Lock create another thread like this one.
	thread Mf2(FMoveBackward, delay, &flagFreeHorizontal);
	Mf2.detach();
}

void Character::MoveBackward(){
	int delay = 1000;
	while (flagFreeHorizontal == 1){}// wait MoveForward is done.
	flagFreeHorizontal = 1;//Lock create another thread like this one.
	thread Mf2(FMoveBackward, delay, &flagFreeHorizontal);
	Mf2.detach();
}

void Character::Jump(int delay){ 
	thread Mf3(FJump, delay);
	Mf3.detach();
}

void Character::Jump(){
	int delay = 600;
	thread Mf3(FJump, delay);
	Mf3.detach();
}

void Character::Attack(){ 
	thread Mf4(FAttack);
	Mf4.detach();
}

void Character::crouch(int delay){ 
	thread Mf5(Fcrouch, delay);
	Mf5.detach();
}

void Character::crouch(){
	int delay = 1000;
	thread Mf5(Fcrouch, delay);
	Mf5.detach();
}

void Character::upSword(int delay){ 
	thread Mf6(FupSword, delay);
	Mf6.detach();
}

void Character::upSword(){
	int delay = 1000;
	thread Mf6(FupSword, delay);
	Mf6.detach();
}

float Character::getMyPositionX(){ return MyPositionX; }
float Character::getMyPositionY(){ return MyPositionY; }
float Character::getEnemyPositionX(){ return EnemyPositionX; }
float Character::getEnemyPositionY(){ return EnemyPositionY; }

float Character::getModuleDistanceAvatars(){// Return the module distance between the two avatars.
	if (MyPositionX >= EnemyPositionX){
		return MyPositionX - EnemyPositionX;
	}
	else {
		return  EnemyPositionX - MyPositionX;
	}
}
	
int Character::getRunOrFight(){// Return 0 if both avatar are in the same position, return 2 if they need to fight (killer is between runner and it way), return 1 if they need to run (Runner has a free way to run).
	if (AvatarColor == 1){
		if ((MyPositionX - EnemyPositionX) > 0){
			return 1;
		}
		else {
			return 2;
		}
	}
	else {
		if ((MyPositionX - EnemyPositionX) > 0){
			return 2;
		}
		else {
			return 1;
		}
	}
}

void Character::setAvatarColor(int color){// 1 = Yellow, 2 = Orange
	AvatarColor = color;
}

int Character::getRunner(){ return Runner; }

void Character::ActionThead(){}

void Character::setCommands(void(mf)(int delay, int *f), void(mb)(int delay, int *f), void(j)(int delay), void(a)(), void(c)(int delay), void(up)(int delay)){
	FMoveForward = mf;
	FMoveBackward = mb;
	FJump = j;
	FAttack = a;
	Fcrouch = c;
	FupSword = up;
}

void Character::test(){
	int f;
	FMoveForward(0, &f);
	FMoveBackward(0, &f);
	FJump(0);
	FAttack();
	Fcrouch(0);
	FupSword(0);
}

void Character::playThread(){
	thread jj([this] { ActionThead(); });
	jj.detach();
}