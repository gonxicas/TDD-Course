#include "../src/Dollar.h"
#include "../src/Euro.h"
#include "gtest/gtest.h"

TEST(MoneySuite, A_Dollar_Multiplied_By_Amount_Returns_Dollar_Times_Amount)
{
	const auto five = Dollar(5);
	ASSERT_EQ(five.Times(2), Dollar(10));
	ASSERT_EQ(five.Times(3), Dollar(15));
}

TEST(MoneySuite, Five_Dollars_Are_Equal_To_Other_Five_Dollars)
{
	ASSERT_TRUE(Dollar(5) == Dollar(5));
	ASSERT_FALSE(Dollar(5) == Dollar(6));

	ASSERT_TRUE(Euro(5) == Euro(5));
	ASSERT_FALSE(Euro(5) == Euro(6));
}

TEST(MoneySuite, An_Euro_Multiplied_By_Amount_Returns_Euro_Times_Amount)
{
	const auto five = Euro(5);
	ASSERT_EQ(five.Times(2), Euro(10));
	ASSERT_EQ(five.Times(3), Euro(15));
}