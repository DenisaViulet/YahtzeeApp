#include "pch.h"
#include "CppUnitTest.h"

#include "Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuartoTests
{
	TEST_CLASS(BoardTests)
	{
	public:

		//TEST_METHOD(DefaultConstructorEmptyBoard)
		//{
		//	Board board;
		//	Board::Position position;
		//	int i, j;
		//	 position.first=i;
		//	//auto& [i, j] = position;
		//	 position.second = j;
		//	for ( i = 0; i < Board::kHeight; ++i)
		//		for ( j = 0; j < Board::kWidth; ++j)
		//			if (board[position].
		//				Assert::Fail();
		//}


		TEST_METHOD(GetAtMinusOneOne)
		{
			Board board;
			Board::Position position{ -1, 1 };

			Assert::ExpectException<const char*>( [&]() {
				board[position];
			});
		}

		/*TEST_METHOD(GetAtMinusOneOneConst)
		{
			const Board board;
			Board::Position position{ -1, 1 };

			Assert::ExpectException<std::out_of_range>([&]() {
				board[position];
			});
		}*/

		TEST_METHOD(GetAtOneMinusOne)
		{
			Board board;
			Board::Position position{ 1, -1 };

			Assert::ExpectException<const char*>([&]() {
				board[position];
			});
		}

		/*TEST_METHOD(GetAtOneMinusOneConst)
		{
			const Board board;
			Board::Position position{ 1, -1 };

			Assert::ExpectException<std::out_of_range>([&]() {
				board[position];
			});
		}*/
	};
}