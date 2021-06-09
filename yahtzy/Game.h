#pragma once
#include"Board.h"
#include"Dice.h"
#include"Player.h"
//#include "Keyboard.h"
class Game
{
public:
	void Run();
	void Options(Board b, Dice d1, Dice d2, Dice d3, Dice d4, Dice d5,int y[14]);

};

