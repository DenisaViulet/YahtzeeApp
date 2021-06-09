#include "pch.h"
#include "CppUnitTest.h"

#include "Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YahtzeeTests
{
	TEST_CLASS(PlayerTests)
	{
	public:

		TEST_METHOD(ThreeOfThree)
		{
			Board board;
			Dice d1, d2, d3,  d4, d5;
			if (board.ThreeOfaKind(d1, d2, d3, d4, d5) != board.Three(d1, d2, d3, d4, d5))
				Assert::Fail;
		
		}


		TEST_METHOD(FourOfFour)
		{
			Board board;
			Dice d1, d2, d3, d4, d5;
			if (board.FourOfaKind(d1, d2, d3, d4, d5) != board.Four(d1, d2, d3, d4, d5))
				Assert::Fail;
		}


		TEST_METHOD(ScoredYahtzee)
		{
			Board board;
			Assert::IsTrue(board.CheckYatzhe());
		}

		TEST_METHOD(FullHouseAndThreeOK)
		{
			Board board;
			Dice d1, d2, d3, d4, d5;
			if (board.ThreeOfaKind(d1, d2, d3, d4, d5) == 0 && board.FullHouse(d1, d2, d3, d4, d5) == 0);
				Assert::Fail;
		}

	};
}