/*
* HACKBOT - Project, Version 1.00.
*
* João Ricardo Louzada
* joaotande@yahoo.com.br
* Itajubá - MG, UNIFEI 2014
* Aqui é Brasil PORRA!
*
* ABOUT THIS PROJECT.
* This code is a hack for the game Nidhogg. With this code is possible
* construct two different bots in order to control the avatars during
* the game and make them fight.
*
* HOW TO USE IT.
* You can build your own bot inside of the function ActionThead() of 
* playerone or playertwo. You also can create others player classes 
* by creating a character's son class. After that you just need to 
* set your players in the main() function using a1.setPlayerYellow();
* and a1.setPlayerOrange();.
*/

#include <iostream>
#include <windows.h>
#include <iostream>
#include <thread>        
#include "arena.h"
#include "playerone.h"
#include "playertwo.h"
using namespace std;

int main()
{
	Arena a1;                                       
	CPlayerOne p1;
	CPlayerTwo p2;

	a1.setPlayerYellow(p1);//Select Yellow Player.
	a1.setPlayerOrange(p2);//Select Orange Player.
	a1.startFight();//Set game stuffs and start thread that update players position. 
	p1.playThread();//Start Player 1 Thread.
	p2.playThread();//Start Player 2 Thread.
		
	while (1){}
	system("pause");
	return 0;
}

