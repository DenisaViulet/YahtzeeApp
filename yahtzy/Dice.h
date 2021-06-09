#pragma once
#include<cstdlib>
#include<iostream>
class Dice
{
private:
	bool keep;
public:
	enum class Faces:uint8_t
	{
		Face1,
		Face2,
		Face3,
		Face4,
		Face5,
		Face6
	};
public:
	Dice();
	Dice(Faces face);
	Faces GetFace() const;
	int IsKept();
	void Kept(bool kept);
	const Faces Roll();
	const void PrintDice(Dice &d);
	friend std::ostream& operator<<(std::ostream& out, const Dice d)
	{
		out << d;
		return out;
	}

private:
	Faces m_face;
};