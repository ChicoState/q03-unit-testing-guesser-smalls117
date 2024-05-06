/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GuesserTest, rightGuess) {
	Guesser my_guess("hat");
	bool guess = my_guess.match("hat");
	ASSERT_EQ(true, guess);
}

TEST(GuesserTest, wrongGuess) {
	Guesser my_guess("Hello");
	bool guess = my_guess.match("power");
	ASSERT_EQ(false, guess);
}

TEST(GuesserTest, longGuess) {
	Guesser my_guess("lamp post");
	ASSERT_EQ(false, my_guess.match("lamp"));
}

TEST(GuesserTest, shotGuess) {
	Guesser my_guess("money");
	ASSERT_EQ(false, my_guess.match("money doesn't grow on trees"));
}
docker build -t cpp-container .