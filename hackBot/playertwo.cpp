/*
João Ricardo Louzada
joaotande@yahoo.com.br
Itajubá - MG, UNIFEI 2014
Aqui é Brasil PORRA!
*/

#include "playertwo.h"

void CPlayerTwo::ActionThead(){
	/*
	Instructions:

	1- The delay argument that the functions needs is the time in millisecond that the function
	will work simulating the press of a key.

	2- All the commands will run in separated threads, so if you want to run and after it to jump
	you need to use a Sleep(X) command, Ex:

	MoveForward(1000);// Run during 1000 millisecond.
	Sleep(1000);// Wait the 1000 millisecond while the avatar runs.
	Jump(600);// Jump during 600 millisecond.

	If you do not use the Sleep(X) function the avatar will do all the commands in the same time.

	//Jump ahead block
	MoveForward(600);// Run during 600 millisecond.
	Jump(600);// Jump during 600 millisecond.

	3- In order to create a bot you can program using this class, you can create new functions, create new threads,
	create other classes to use in this classe,	but you can not acess the classes Arena, Character, or Main.cpp.

	4 - Functions:

	Commands you can use to play.
	--------------------------------
	void MoveForward(int delay);
	void MoveForward();//Standard time delay = 1000
	void MoveBackward(int delay);
	void MoveBackward();//Standard time delay = 1000
	void Jump(int delay);
	void Jump();//Standard time delay = 600
	void Attack();
	void crouch(int delay);
	void crouch();//Standard time delay = 1000
	void upSword(int delay);
	void upSword();//Standard time delay = 1000
	Sleep(int delay);

	Information you need to get to play.
	-------------------------
	float getMyPositionX();// Return your avatar position.
	float getEnemyPositionX();// Return your enemy avatar position.
	int getRunner();// If it return 1 you need to run to win. if it returns 2 your enemy needs to run to win. If it return 0 both of the avatars need to fight before run. If it return 3 it is fail, check again...
	float getModuleDistanceAvatars();// Return the module distance between the two avatars.
	int getRunOrFight();// Return 0 if both avatar are in the same position, return 2 if they need to fight (killer is between runner and it way), return 1 if they need to run (Runner has a free way to run).
	*/

	while (1){
		//################Example of a bot (You can erase and rewrite this code)(You need to program you bot inside of this While() block)
		MoveForward();
		Jump();
		Sleep(1000);
		MoveBackward();
		Jump();
		Sleep(1000);
		//################Example of a bot (You can erase and rewrite this code)(You need to program you bot inside of this While() block)

	}
}