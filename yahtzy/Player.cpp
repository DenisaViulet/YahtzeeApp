#include "Player.h"


Player::Player(const std::string& name) : m_name(name), m_score(0), m_special_score(0)
{
}
Player::Player()
{
}

Player::~Player()
{
}

bool Player::Special_Bonus()
{
	if (getSpecialScore() >= 63)
	{
		setScore(35);
		
		std::cout << "Your special bonus has been delivered! Great job ! :)" << std::endl;
		return true;
	}
	else {
		
		return false;
	}
}

int Player::getScore() 
{
	return Player::m_score;
}

int Player::getSpecialScore()
{
	return Player::m_special_score;
}


void Player::setScore(int sc)
{
	//m_score=getScore();
	Player::m_score += sc;
}

void Player::setSpecialScore(int sc)
{
	Player::m_special_score += sc;
}



std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << player.m_name ;
	return out;
}



