#include "pch.h"

#include "CppUnitTest.h"
#include <sstream>


#include "Dice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework
		{
			template<> inline std::wstring ToString<Dice::Faces>(const Dice::Faces& t)
			{
				switch (t)
				{
				case Dice::Faces::Face1:
					return L"Face1";
				case Dice::Faces::Face2:
					return L"Face2";
				case Dice::Faces::Face3:
					return L"Face3";
				case Dice::Faces::Face4:
					return L"Face4";
				case Dice::Faces::Face5:
					return L"Face5";
				case Dice::Faces::Face6:
					return L"Face6";
				}
			}
		}
	}
}
namespace YahtzeeTests
{
	TEST_CLASS(DiceTests)
	{
	public:

		TEST_METHOD(DefaultConstructor)
		{
			Dice dice(Dice::Faces::Face1);
			Assert::AreEqual(Dice::Faces::Face1, dice.GetFace());

		}

		TEST_METHOD(ADiceIsKept)
		{
			Dice dice(Dice::Faces::Face1);
			Assert::IsTrue(dice.IsKept());

		}

		TEST_METHOD(SameDicesAfterRolling)
		{
			Dice dice(Dice::Faces::Face3);
			Dice dice1(Dice::Faces::Face1);
			dice.Roll(); dice1.Roll();
			Assert::AreEqual(dice1.GetFace(), dice.GetFace());
		}

		TEST_METHOD(Print)
		{
			Dice dice(Dice::Faces::Face3);

			std::stringstream stream;
			stream << dice;
			Assert::AreEqual(std::string("0001"), stream.str(), L"If you see this message, dice is not printed correctly");
		}
	};
}