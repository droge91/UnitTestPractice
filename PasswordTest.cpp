/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, two_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}
TEST(PasswordTest, mixedcases)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZzZ");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, special_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z@Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, numbers)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z1Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, noleading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("qwrAWf");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, specialLeading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("$$$$Z");
	ASSERT_EQ(4, actual);
}
TEST(hasmixedcase, mixedCase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ZzZ");
	ASSERT_TRUE(actual);
}
TEST(hasmixedcase, upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ZZZ");
	ASSERT_FALSE(actual);
}
TEST(hasmixedcase, lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zzz");
	ASSERT_FALSE(actual);
}
TEST(hasmixedcase, emptyl)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_FALSE(actual);
}
