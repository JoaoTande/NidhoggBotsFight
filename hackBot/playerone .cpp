/*
Jo�o Ricardo Louzada
joaotande@yahoo.com.br
Itajub� - MG, UNIFEI 2014
Aqui � Brasil PORRA!
*/

#include "playerone.h"

void CPlayerOne::ActionThead(){
	/*Commands you can use to play.
	  void MoveForward(int delay);
	  void MoveBackward(int delay);
	  void Jump(int delay);
	  void Attack();
	  void crouch(int delay);
	  void upSword(int delay);*/
	
	while (1){
		//################Example of a bot (You can erase and rewrite this code)(You need to program you bot inside of this While() block)
		MoveForward(0);
		Attack();
		MoveBackward(0);
		Attack();
		//################Example of a bot (You can erase and rewrite this code)(You need to program you bot inside of this While() block)
	}
}

