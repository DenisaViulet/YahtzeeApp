#pragma once
#include<vector>
#include<optional>
#include"Player.h"
#include"Dice.h"

class Board
{


public:
	enum class Place : uint8_t
	{
		one,
		two,
		three,
		four,
		five,
		six,
		section_bonus,
		three_of_a_kind,
		four_of_a_kind,
		full_house,
		small_straight,
		large_straight,
		yatzy,
		chance
	};
public:
	using Position = std::pair< uint16_t, uint16_t>;
public:
	void Elemente(int x, Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	~Board();
	//bool FunctionKept(bool ok);

public:
	static void Keyboard(int key, Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);

	int One(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int Two(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int Three(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int Four(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int Five(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int Six(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int ThreeOfaKind(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int FourOfaKind(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int Yatzhee(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int Chance(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int FullHouse(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int SmallStraight(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	int LargeStraight(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5);
	void SetBoard();
	void SetSpecial();
	bool CheckYatzhe();
	void Hints(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5, bool roll);
private:
	//Table(Face face);

	uint16_t m_board[7][2];
	uint16_t m_hint[7][2];

};