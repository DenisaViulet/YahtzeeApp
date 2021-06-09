#include "pch.h"
#include "CppUnitTest.h"

#include "Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YahtzeeTests
{
	TEST_CLASS(PlayerTests)
	{
	public:

		TEST_METHOD(SameScore)
		{
			Player player1("Player1");
			Player player2("Player2");
			Assert::AreEqual(player1.getScore(), player2.getScore());
		}


		TEST_METHOD(HasEarnedSpecialBonus)
		{
			Player player1("Player1");
			if (player1.getSpecialScore() == 0)
				Assert::Fail;
		}
		

		TEST_METHOD(HasEarnedSpecialBonus)
		{
			Player player1("Player1");
			if (player1.getSpecialScore() == 0)
				Assert::Fail;
		}
	};
}