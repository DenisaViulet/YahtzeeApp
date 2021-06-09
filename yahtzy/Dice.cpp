#include "Dice.h"

Dice::Dice(){}

Dice::Dice(Faces face) :m_face(face) {};

Dice::Faces Dice::GetFace() const
{
	return m_face;
}

int Dice::IsKept()
{
	if (keep == false)
		return 0;
	return 1;
}

void Dice::Kept(bool kept)
{
	keep = kept;
}

const Dice::Faces Dice::Roll()
{
	Faces x= static_cast<Faces>(rand() % 6);
	switch (x)
	{
	case Faces::Face1:
		m_face = Dice::Faces::Face1;
		return m_face;
		break;

	case Faces::Face2:
		m_face = Dice::Faces::Face2;
		return m_face;
		break;

	case Faces::Face3:
		m_face = Dice::Faces::Face3;
		return m_face;
		break;

	case Faces::Face4:
		m_face = Dice::Faces::Face4;
		return m_face;
		break;

	case Faces::Face5:
		m_face = Dice::Faces::Face5;
		return m_face;
		break;

	case Faces::Face6:
		m_face = Dice::Faces::Face6;
		return m_face;
		break;
	}
}


const void Dice::PrintDice(Dice &d)
{
	Faces i = d.GetFace();

	switch (i)
	{
	case Faces::Face1:
	{
		std::cout << "*********\n"
			<< "*       *\n"
			<< "*   X   *\n"
			<< "*       *\n"
			<< "*********\n";
		break;
	}
	case Faces::Face2:
	{
		std::cout << "*********\n"
			<< "*   X   *\n"
			<< "*       *\n"
			<< "*   X   *\n"
			<< "*********\n";
		break;

	}
	case Faces::Face3:
	{	std::cout << "*********\n"
		<< "*   X   *\n"
		<< "*   X   *\n"
		<< "*   X   *\n"
		<< "*********\n";
	break;

	}
	case Faces::Face4:
	{
		std::cout << "*********\n"
			<< "* X   X *\n"
			<< "*       *\n"
			<< "* X   X *\n"
			<< "*********\n";
		break;
	}
	case Faces::Face5:
	{
		std::cout << "*********\n"
			<< "* X   X *\n"
			<< "*   X   *\n"
			<< "* X   X *\n"
			<< "*********\n";
		break;
	}
	case Faces::Face6:
	{
		std::cout << "*********\n"
			<< "* X   X *\n"
			<< "* X   X *\n"
			<< "* X   X *\n"
			<< "*********\n";
		break;

	}

	default:
		break;
	}

}