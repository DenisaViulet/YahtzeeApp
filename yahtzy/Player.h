#pragma once
//#include<iostream>
#include"Dice.h"
#include"Board.h"
#include<vector>

class Player
{
private:

	std::string m_name;
	
	std::vector<Dice> dices;

public:

	bool Special_Bonus();
	int getScore();
	int getSpecialScore();
	void setScore(int sc);
	void setSpecialScore(int sc);
	friend std::ostream& operator<<(std::ostream& out, const Player& player);

private:
	uint8_t m_score;
	uint8_t m_special_score;
public:
	Player(const std::string& name);
	Player();
	~Player();

};

