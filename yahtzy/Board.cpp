#include "Board.h"
#include"Dice.h"
#include<iomanip>




void Board::Keyboard(int key, Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	if (key == 1)
		d1.IsKept() == true;

	else if (key == 2)
		d2.IsKept() == true;

	else if (key == 3)
		d3.IsKept() == true;

	else if (key == 4)
		d4.IsKept() == true;

	else if (key == 5)
		d5.IsKept() == true;
}

int Board::One(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	int number_1 = 0;
	if (d1.GetFace() == Dice::Faces::Face1)
		number_1++;
	if (d2.GetFace() == Dice::Faces::Face1)
		number_1++;
	if (d3.GetFace() == Dice::Faces::Face1)
		number_1++;
	if (d4.GetFace() == Dice::Faces::Face1)
		number_1++;
	if (d5.GetFace() == Dice::Faces::Face1)
		number_1++;
	return number_1;

}

int Board::Two(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	int number_2 = 0;
	if (d1.GetFace() == Dice::Faces::Face2)
		number_2 += 2;
	if (d2.GetFace() == Dice::Faces::Face2)
		number_2 += 2;
	if (d3.GetFace() == Dice::Faces::Face2)
		number_2 += 2;
	if (d4.GetFace() == Dice::Faces::Face2)
		number_2 += 2;
	if (d5.GetFace() == Dice::Faces::Face2)
		number_2 += 2;

	return number_2;
}

int Board::Three(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	int number_3 = 0;
	if (d1.GetFace() == Dice::Faces::Face3)
		number_3 += 3;
	if (d2.GetFace() == Dice::Faces::Face3)
		number_3 += 3;
	if (d3.GetFace() == Dice::Faces::Face3)
		number_3 += 3;
	if (d4.GetFace() == Dice::Faces::Face3)
		number_3 += 3;
	if (d5.GetFace() == Dice::Faces::Face3)
		number_3 += 3;


	return number_3;
}

int Board::Four(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	int number_4 = 0;
	if (d1.GetFace() == Dice::Faces::Face4)
		number_4 += 4;
	if (d2.GetFace() == Dice::Faces::Face4)
		number_4 += 4;
	if (d3.GetFace() == Dice::Faces::Face4)
		number_4 += 4;
	if (d4.GetFace() == Dice::Faces::Face4)
		number_4 += 4;
	if (d5.GetFace() == Dice::Faces::Face4)
		number_4 += 4;

	return number_4;
}

int Board::Five(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	int number_5 = 0;
	if (d1.GetFace() == Dice::Faces::Face5)
		number_5 += 5;
	if (d2.GetFace() == Dice::Faces::Face5)
		number_5 += 5;
	if (d3.GetFace() == Dice::Faces::Face5)
		number_5 += 5;
	if (d4.GetFace() == Dice::Faces::Face5)
		number_5 += 5;
	if (d5.GetFace() == Dice::Faces::Face5)
		number_5 += 5;

	return number_5;
}

int Board::Six(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	int number_6 = 0;
	if (d1.GetFace() == Dice::Faces::Face6)
		number_6 += 6;
	if (d2.GetFace() == Dice::Faces::Face6)
		number_6 += 6;
	if (d3.GetFace() == Dice::Faces::Face6)
		number_6 += 6;
	if (d4.GetFace() == Dice::Faces::Face6)
		number_6 += 6;
	if (d5.GetFace() == Dice::Faces::Face6)
		number_6 += 6;


	return number_6;
}

int Board::Chance(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	int total;
	total = One(d1, d2, d3, d4, d5) + Two(d1, d2, d3, d4, d5) + Three(d1, d2, d3, d4, d5) + Four(d1, d2, d3, d4, d5) + Five(d1, d2, d3, d4, d5) + Six(d1, d2, d3, d4, d5);

	return total;
}



int Board::ThreeOfaKind(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	if (Six(d1, d2, d3, d4, d5) >= 18)
		return (Chance(d1, d2, d3, d4, d5));
	else if (Five(d1, d2, d3, d4, d5) >= 15)
		return(Chance(d1, d2, d3, d4, d5));
	else if (Four(d1, d2, d3, d4, d5) >= 12)
		return (Chance(d1, d2, d3, d4, d5));
	else if (Three(d1, d2, d3, d4, d5) >= 9)
		return (Chance(d1, d2, d3, d4, d5));
	else if (Two(d1, d2, d3, d4, d5) >= 6)
		return (Chance(d1, d2, d3, d4, d5));
	else if (One(d1, d2, d3, d4, d5) >= 3)
		return (Chance(d1, d2, d3, d4, d5));

	else return 0;
}

int Board::FourOfaKind(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	if (Six(d1, d2, d3, d4, d5) >= 24)
		return (Chance(d1, d2, d3, d4, d5));
	else if (Five(d1, d2, d3, d4, d5) >= 20)
		return(Chance(d1, d2, d3, d4, d5));
	else if (Four(d1, d2, d3, d4, d5) >= 16)
		return (Chance(d1, d2, d3, d4, d5));
	else if (Three(d1, d2, d3, d4, d5) >= 12)
		return (Chance(d1, d2, d3, d4, d5));
	else if (Two(d1, d2, d3, d4, d5) >= 8)
		return (Chance(d1, d2, d3, d4, d5));
	else if (One(d1, d2, d3, d4, d5) >= 4)
		return (Chance(d1, d2, d3, d4, d5));

	else return 0;
}

int Board::Yatzhee(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	if (Six(d1, d2, d3, d4, d5) == 30)
		return 50;
	else if (Five(d1, d2, d3, d4, d5) == 25)
		return 50;
	else if (Four(d1, d2, d3, d4, d5) == 20)
		return 50;
	else if (Three(d1, d2, d3, d4, d5) == 15)
		return 50;
	else if (Two(d1, d2, d3, d4, d5) == 10)
		return 50;
	else if (One(d1, d2, d3, d4, d5) == 5)
		return 50;
	else return 0;
}

int Board::FullHouse(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	bool ok = false;
	if (Six(d1, d2, d3, d4, d5) == 12)
		ok = true;
	else if (Five(d1, d2, d3, d4, d5) == 10)
		ok = true;
	else if (Four(d1, d2, d3, d4, d5) == 8)
		ok = true;
	else if (Three(d1, d2, d3, d4, d5) == 6)
		ok = true;
	else if (Two(d1, d2, d3, d4, d5) == 4)
		ok = true;
	else if (One(d1, d2, d3, d4, d5) == 2)
		ok = true;
	if ((ok) && ThreeOfaKind(d1, d2, d3, d4, d5) != 0)
		return 25;
}

int Board::SmallStraight(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	if (((One(d1, d2, d3, d4, d5) >= 1) || (Five(d1, d2, d3, d4, d5) >= 5)) && (Two(d1, d2, d3, d4, d5) >= 2) && (Three(d1, d2, d3, d4, d5) >= 3) && (Four(d1, d2, d3, d4, d5) >= 4))
		return 30;
	else if ((Three(d1, d2, d3, d4, d5) >= 3) && (Four(d1, d2, d3, d4, d5) <= 4) && (Five(d1, d2, d3, d4, d5) >= 5) && (Six(d1, d2, d3, d4, d5) >= 6))
		return 30;
	else return 0;
}

int Board::LargeStraight(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{
	if (((One(d1, d2, d3, d4, d5) == 1) || (Six(d1, d2, d3, d4, d5) == 6)) && (Two(d1, d2, d3, d4, d5) == 2) && (Three(d1, d2, d3, d4, d5) == 3) && (Four(d1, d2, d3, d4, d5) == 4) && (Five(d1, d2, d3, d4, d5) == 5))
		return 40;
	else return 0;
}

void Board::SetBoard()
{
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
		{
			m_board[i][j] = 0;
			m_hint[i][j] = 0;
		}
}

void Board::SetSpecial()
{
	m_board[6][0] = 35;
}

bool Board::CheckYatzhe()
{
	if (m_board[5][1] != 0)
		return true;
	return false;
}

Board::~Board()
{
}

void Board::Elemente(int x, Dice d1, Dice d2, Dice d3, Dice d4, Dice d5)
{

	switch (x)
	{
	case 1:
	{
		m_board[0][0] = One(d1, d2, d3, d4, d5);
		m_hint[0][0] = 1;
		break;
	}
	case 2:
	{
		m_board[1][0] = Two(d1, d2, d3, d4, d5);
		m_hint[1][0] = 1;
		break;
	}
	case 3:
	{
		m_board[2][0] = Three(d1, d2, d3, d4, d5);
		m_hint[2][0] = 1;
		break;
	}
	case 4:
	{
		m_board[3][0] = Four(d1, d2, d3, d4, d5);
		m_hint[3][0] = 1;
		break;
	}
	case 5:
	{
		m_board[4][0] = Five(d1, d2, d3, d4, d5);
		m_hint[4][0] = 1;
		break;
	}
	case 6:
	{
		m_board[5][0] = Six(d1, d2, d3, d4, d5);
		m_hint[5][0] = 1;
		break;
	}
	case 7:
	{
		m_board[0][1] = ThreeOfaKind(d1, d2, d3, d4, d5);
		m_hint[0][1] = 1;
		break;
	}


	case 8:
	{
		m_board[1][1] = FourOfaKind(d1, d2, d3, d4, d5);
		m_hint[1][1] = 1;
		break;
	}
	case 9:
	{
		m_board[2][1] = FullHouse(d1, d2, d3, d4, d5);
		m_hint[2][1] = 1;
		break;
	}
	case 10:
	{
		m_board[3][1] = SmallStraight(d1, d2, d3, d4, d5);
		m_hint[3][1] = 1;
		break;
	}
	case 11:
	{
		m_board[4][1] = LargeStraight(d1, d2, d3, d4, d5);
		m_hint[4][1] = 1;
		break;
	}
	case 12:
	{
		m_board[5][1] = Yatzhee(d1, d2, d3, d4, d5);
		m_hint[5][1] = 1;
		break;
	}
	case 13:
	{
		m_board[6][1] = Chance(d1, d2, d3, d4, d5);
		m_hint[6][1] = 1;
		break;
	}
	case 14:
	{
		m_board[6][0] = 35;
		m_hint[6][0] = 1;
		break;
	}

	default:
	{
		break;
	}
	}
	std::cout << "_" << std::setfill('_') << std::setw(60) << "\n";
	std::cout << " " << std::setfill(' ') << std::setw(59) << "|";
	std::cout << std::endl << "One"; std::cout << " " << std::setfill(' ') << std::setw(8); std::cout << m_board[0][0]; std::cout << " " << std::setfill(' ') << std::setw(29); std::cout << "Three of a kind"; std::cout << " " << std::setfill(' ') << std::setw(13); std::cout << m_board[0][1]; std::cout << " " << std::setfill(' ') << std::setw(4) << "|\n"; //ThreeOfaKind(d1, d2, d3, d4, d5) << std::endl;
	std::cout << "_" << std::setfill('_') << std::setw(60) << "|\n";
	std::cout << " " << std::setfill(' ') << std::setw(59) << "|";
	std::cout << std::endl << "Two"; std::cout << " " << std::setfill(' ') << std::setw(8); std::cout << m_board[1][0]; std::cout << " " << std::setfill(' ') << std::setw(28); std::cout << "Four of a kind"; std::cout << " " << std::setfill(' ') << std::setw(14); std::cout << m_board[1][1]; std::cout << " " << std::setfill(' ') << std::setw(4) << "|\n"; //ThreeOfaKind(d1, d2, d3, d4, d5) << std::endl;
	std::cout << "_" << std::setfill('_') << std::setw(60) << "|\n";
	std::cout << " " << std::setfill(' ') << std::setw(59) << "|";
	std::cout << std::endl << "Three"; std::cout << " " << std::setfill(' ') << std::setw(6); std::cout << m_board[2][0]; std::cout << " " << std::setfill(' ') << std::setw(24); std::cout << "Full house"; std::cout << " " << std::setfill(' ') << std::setw(18); std::cout << m_board[2][1]; std::cout << " " << std::setfill(' ') << std::setw(4) << "|\n"; //ThreeOfaKind(d1, d2, d3, d4, d5) << std::endl;
	std::cout << "_" << std::setfill('_') << std::setw(60) << "|\n";
	std::cout << " " << std::setfill(' ') << std::setw(59) << "|";
	std::cout << std::endl << "Four"; std::cout << " " << std::setfill(' ') << std::setw(7); std::cout << m_board[3][0]; std::cout << " " << std::setfill(' ') << std::setw(28); std::cout << "Small straight"; std::cout << " " << std::setfill(' ') << std::setw(14); std::cout << m_board[3][1]; std::cout << " " << std::setfill(' ') << std::setw(4) << "|\n"; //ThreeOfaKind(d1, d2, d3, d4, d5) << std::endl;
	std::cout << "_" << std::setfill('_') << std::setw(60) << "|\n";
	std::cout << " " << std::setfill(' ') << std::setw(59) << "|";
	std::cout << std::endl << "Five"; std::cout << " " << std::setfill(' ') << std::setw(7); std::cout << m_board[4][0]; std::cout << " " << std::setfill(' ') << std::setw(28); std::cout << "Large Straight"; std::cout << " " << std::setfill(' ') << std::setw(14); std::cout << m_board[4][1]; std::cout << " " << std::setfill(' ') << std::setw(4) << "|\n"; //ThreeOfaKind(d1, d2, d3, d4, d5) << std::endl;
	std::cout << "_" << std::setfill('_') << std::setw(60) << "|\n";
	std::cout << " " << std::setfill(' ') << std::setw(59) << "|";
	std::cout << std::endl << "Six"; std::cout << " " << std::setfill(' ') << std::setw(8); std::cout << m_board[5][0]; std::cout << " " << std::setfill(' ') << std::setw(23); std::cout << "Yatzy"; std::cout << " " << std::setfill(' ') << std::setw(19); std::cout << m_board[5][1]; std::cout << " " << std::setfill(' ') << std::setw(4) << "|\n"; //ThreeOfaKind(d1, d2, d3, d4, d5) << std::endl;
	std::cout << "_" << std::setfill('_') << std::setw(60) << "|\n";
	std::cout << " " << std::setfill(' ') << std::setw(59) << "|";
	std::cout << std::endl << "Special bonus"; std::cout << " " << std::setfill(' ') << std::setw(8); std::cout << m_board[6][0]; std::cout << " " << std::setfill(' ') << std::setw(13); std::cout << "Chance"; std::cout << " " << std::setfill(' ') << std::setw(19); std::cout << m_board[6][1]; std::cout << " " << std::setfill(' ') << std::setw(4) << "|\n"; //ThreeOfaKind(d1, d2, d3, d4, d5) << std::endl;
	std::cout << "_" << std::setfill('_') << std::setw(60) << "|\n";
	std::cout << std::endl;
}


void Board::Hints(Dice d1, Dice d2, Dice d3, Dice d4, Dice d5, bool roll)
{
	uint16_t sum = Chance(d1, d2, d3, d4, d5);


	if (Six(d1, d2, d3, d4, d5) >= 18 && m_hint[5][0] != 1)
	{
		std::cout << "Choose six, you may get special bonus\n";
		return;
	}
	if (Five(d1, d2, d3, d4, d5) >= 15 && m_hint[4][0] != 1)
	{
		std::cout << "Choose five, you may get special bonus\n";
		return;
	}
	if (Four(d1, d2, d3, d4, d5) >= 12 && m_hint[3][0] != 1)
	{
		std::cout << "Choose four, you may get special bonuss\n";
		return;
	}

	if (LargeStraight(d1, d2, d3, d4, d5) == 40 && m_hint[4][1] != 1)
	{
		std::cout << "Choose Large Straight\n";
		return;
	}
	if (SmallStraight(d1, d2, d3, d4, d5) == 30 && m_hint[4][1] != 1 && roll == true)
	{
		std::cout << "You can keep the small straight, or risk and aim for large straight\n";
		return;
	}
	if (SmallStraight(d1, d2, d3, d4, d5) == 30 && m_hint[3][1] != 1)
	{
		std::cout << "Choose SmallStraight\n";
		return;

	}
	 if (Yatzhee(d1, d2, d3, d4, d5) == 50)
	{
		std::cout << "Choose yahtzee\n";
		return;
	}
	if (FullHouse(d1, d2, d3, d4, d5) == 25 && m_hint[2][1] != 1)
	{
		std::cout << "Choose Full house\n";
		return;
	}
	if (ThreeOfaKind(d1, d2, d3, d4, d5) != 0 && Six(d1, d2, d3, d4, d5) <= 18 && Five(d1, d2, d3, d4, d5) <= 15 && m_hint[2][1] != 1 && roll == true)
	{
		std::cout << "Keep the dices you have three of and you may get a full house\n";
		return;
	}
	if (One(d1, d2, d3, d4, d5) >= 4 && m_hint[0][0] != 1)
	{
		std::cout << "Choose one\n";
		return;
	}
	if (Two(d1, d2, d3, d4, d5) >= 8 && m_hint[1][0] != 1)
	{
		std::cout << "Choose two\n";
		return;
	}
	if (Three(d1, d2, d3, d4, d5) >= 12 && m_hint[2][0] != 1)
	{
		std::cout << "Choose three\n";
		return;
	}
	if (ThreeOfaKind(d1, d2, d3, d4, d5) >= 15 && m_hint[0][1] != 1)
	{
		std::cout << "Choose three of a kind\n";
		return;
	}
	if (ThreeOfaKind(d1, d2, d3, d4, d5) >= 15 && m_hint[1][1] != 1 && m_hint[0][1] != 1 && roll == true)
	{
		std::cout << "Choose three of a kind or risk and aim for a four of a kind\n";
		return;
	}
	if (FourOfaKind(d1, d2, d3, d4, d5) && m_hint[1][1] != 1)
	{
		std::cout << "Choose four of a kind\n";
		return;
	}

	if((d1.GetFace()==Dice::Faces::Face1|| d2.GetFace() == Dice::Faces::Face1 || d3.GetFace() == Dice::Faces::Face1 || d4.GetFace() == Dice::Faces::Face1 || d5.GetFace() == Dice::Faces::Face1)
		&& (d1.GetFace() == Dice::Faces::Face2 || d2.GetFace() == Dice::Faces::Face2 || d3.GetFace() == Dice::Faces::Face2 || d4.GetFace() == Dice::Faces::Face2 || d5.GetFace() == Dice::Faces::Face2)
		&& (d1.GetFace() == Dice::Faces::Face3 || d2.GetFace() == Dice::Faces::Face3 || d3.GetFace() == Dice::Faces::Face3 || d4.GetFace() == Dice::Faces::Face3 || d5.GetFace() == Dice::Faces::Face3)
		&& roll==true)
	{
		std::cout << "Keep the 3 consecutive dices and aim for Small straight or Large straight\n";
		return;
	}

	if ((d1.GetFace() == Dice::Faces::Face4 || d2.GetFace() == Dice::Faces::Face4 || d3.GetFace() == Dice::Faces::Face4 || d4.GetFace() == Dice::Faces::Face4|| d5.GetFace() == Dice::Faces::Face4)
		&& (d1.GetFace() == Dice::Faces::Face2 || d2.GetFace() == Dice::Faces::Face2 || d3.GetFace() == Dice::Faces::Face2 || d4.GetFace() == Dice::Faces::Face2 || d5.GetFace() == Dice::Faces::Face2)
		&& (d1.GetFace() == Dice::Faces::Face3 || d2.GetFace() == Dice::Faces::Face3 || d3.GetFace() == Dice::Faces::Face3 || d4.GetFace() == Dice::Faces::Face3 || d5.GetFace() == Dice::Faces::Face3)
		&& roll == true)
	{
		std::cout << "Keep the 3 consecutive dices and aim for Small straight or Large straight\n";
		return;
	}

	if ((d1.GetFace() == Dice::Faces::Face4 || d2.GetFace() == Dice::Faces::Face4 || d3.GetFace() == Dice::Faces::Face4 || d4.GetFace() == Dice::Faces::Face4 || d5.GetFace() == Dice::Faces::Face4)
		&& (d1.GetFace() == Dice::Faces::Face5 || d2.GetFace() == Dice::Faces::Face5 || d3.GetFace() == Dice::Faces::Face5 || d4.GetFace() == Dice::Faces::Face5 || d5.GetFace() == Dice::Faces::Face5)
		&& (d1.GetFace() == Dice::Faces::Face3 || d2.GetFace() == Dice::Faces::Face3 || d3.GetFace() == Dice::Faces::Face3 || d4.GetFace() == Dice::Faces::Face3 || d5.GetFace() == Dice::Faces::Face3)
		&& roll == true)
	{
		std::cout << "Keep the 3 consecutive dices and aim for Small straight or Large straight\n";
		return;
	}
	 if (m_hint[6][1] != 1 && Chance(d1, d2, d3, d4, d5) >= 24)
	{
		std::cout << "Take chance\n";
		return;
	}
	 if (roll == true)
	{
		std::cout << "Roll again and try to keep the highest dices\n";
	}
	else
	{
		std::cout << "Choose the least important option\n";
		return;
	}
}