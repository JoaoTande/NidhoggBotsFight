#include <iostream>
#include <string>
#include <thread>  
using namespace std;

#ifndef CHARACTER_CLASS
#define CHARACTER_CLASS


class Character
{
private:
	float MyPositionX;
	float MyPositionY;
	float EnemyPositionX;
	float EnemyPositionY;
	int Runner;

	void (*FMoveForward)(int);
	void (*FMoveBackward)(int);
	void (*FJump)(int);
	void (*FAttack)();
	void (*Fcrouch)(int);
	void (*FupSword)(int);

public:
	
	void updateInformation(float, float, float, float, int);
	void setCommands(void(mf)(int delay), void(mb)(int), void(j)(int), void(a)(), void(c)(int), void(up)(int));

	void MoveForward(int delay);
	void MoveBackward(int delay);
	void Jump(int delay);
	void Attack();
	void crouch(int delay); 
	void upSword(int delay);

	float getMyPositionX();
	float getEnemyPositionX();
	float getMyPositionY();
	float getEnemyPositionY();

	int getRunner();

	virtual void ActionThead();
	void playThread();

	void test();
		
};

#endif