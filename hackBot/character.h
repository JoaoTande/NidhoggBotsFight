/*
* HACKBOT - Project, Version 1.00.
*
* João Ricardo Louzada
* joaotande@yahoo.com.br
* Itajubá - MG, UNIFEI 2014
* Aqui é Brasil PORRA!
*
* CLASS CHARACTER
*/
#ifndef CHARACTER_CLASS
#define CHARACTER_CLASS

#include <iostream>
#include <string>
#include <thread>  
#include <iomanip>
#include <Windows.h>
#include <TlHelp32.h> //PROCESSENTRY
#include <windows.h>
using namespace std;

class Arena;

class Character
{
private:
	float MyPositionX;
	float MyPositionY;
	float EnemyPositionX;
	float EnemyPositionY;
	int Runner;
	int AvatarColor;// 1 = Yellow, 2 = Orange

	int flagFreeHorizontal;//Flag to avoid MoveForward() and MoveBackward() in the same time. (it avoid the avatar to be stuck)

	void(*FMoveForward)(int,int*);
	void(*FMoveBackward)(int,int*);
	void (*FJump)(int);
	void (*FAttack)();
	void (*Fcrouch)(int);
	void (*FupSword)(int);

	
public:
	
	void updateInformation(float, float, float, float, int);
	void setCommands(void(mf)(int delay, int *f), void(mb)(int, int *f), void(j)(int), void(a)(), void(c)(int), void(up)(int));
	void setAvatarColor(int color);// 1 = Yellow, 2 = Orange

	void MoveForward(int delay);
	void MoveForward();
	void MoveBackward(int delay);
	void MoveBackward();
	void Jump(int delay);
	void Jump();
	void Attack();
	void crouch(int delay);
	void crouch();
	void upSword(int delay);
	void upSword();

	float getMyPositionX();
	float getEnemyPositionX();
	float getMyPositionY();
	float getEnemyPositionY();
	float getModuleDistanceAvatars();// Return the module distance between the two avatars.
	int getRunOrFight();// Return 0 if both avatar are in the same position, return 2 if they need to fight (killer is between runner and it way), return 1 if they need to run (Runner has a free way to run).
	int getRunner();// if it return 1 you need to run to win. if it returns 2 your enemy needs to run to win. return 0 both of the avatars need to fight before run. return 3 it is fail... wait...

	virtual void ActionThead();
	void playThread();

	void test();
		
};

#endif