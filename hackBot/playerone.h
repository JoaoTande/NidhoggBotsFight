#include <iostream>
#include <string>
#include "character.h"
using namespace std;

#ifndef CPLAYERONE_CLASS
#define CPLAYERONE_CLASS


class CPlayerOne : public Character{
public:
	
	virtual void ActionThead();
};

#endif