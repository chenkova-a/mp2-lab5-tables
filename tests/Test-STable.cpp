#include"../Tables/Table.h"
#include"../gtest/gtest.h"
#include "../Tables/Sorted-table.h"

struct tp {
	int c;
	double d;
};
TEST(STable, can_create_a_table)
{
	ASSERT_NO_THROW(STable A);
}

TEST(STable, can_insert_a_row)
{
	STable H;
	Polynom A;
	row r;
	r.data = &A;
	r.key = "Polynom1";
	ASSERT_NO_THROW(H.Insert(r));
}

TEST(STable, can_find_a_polynom)
{
	string tm[5];
	Polynom M[5];
	STable H;
	string s;
	row r;

	for (int i = 0; i < 3; i++) {
		tm[i] = "x^";
		tm[i] += to_string(i + 1);
		tm[i] += "y^";
		tm[i] += to_string(i + 1);
		tm[i] += "z^";
		tm[i] += to_string(i + 1);

		M[i].loadString(tm[i]);

		s = "Polynom";
		s += to_string(i);

		r.data = &M[i];
		r.key = s;

		H.Insert(r);
	}

	s = "Polynom2";

	Polynom B;
	B = M[2];

	EXPECT_EQ(B, *H.Search(s));
}

TEST(STable, can_not_find_a_missing_polynom)
{
	string tm;
	tm = "x^1y^2z^2";

	string s = "Polynom3";
	string s1 = "Polynom4";

	Polynom A(tm);

	row r;
	r.data = &A;
	r.key = s;

	STable H;

	H.Insert(r);
	EXPECT_EQ(NULL, H.Search(s1));
}

TEST(STable, can_delete_a_polynom)
{
	STable H;
	string s;
	row r;

	s = "Polynom1";

	Polynom A("x^1y^1z^1");

	r.data = &A;
	r.key = s;

	H.Insert(r);
	Polynom B;

	B = A;

	EXPECT_EQ(B, *H.Search(s));
	H.Delete(s);

	EXPECT_EQ(NULL, H.Search(s));
}