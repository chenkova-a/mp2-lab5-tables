#pragma once

#include"../Tables/Table.h"
#include"../gtest/gtest.h"
#include "../Tables/Unsorted-table.h"
struct tp {
	int c;
	double d;
};
TEST(Disordered, can_create_a_table)
{
	ASSERT_NO_THROW(USTable A);
}

TEST(Disordered, can_insert_a_row)
{
	USTable H;
	Polynom A;
	row r;
	r.data = &A;
	r.key = "Polynom1";
	ASSERT_NO_THROW(H.Insert(r));
}

TEST(USTable, can_find_a_polynom)
{
	tp pol[5];
	string tm[5];
	for (int i = 0; i < 3; i++) {
		tm[i] = "x^";
		tm[i] += to_string(i + 1);
		tm[i] += "y^";
		tm[i] += to_string(i + 1);
		tm[i] += "z^";
		tm[i] += to_string(i + 1);
	}
	string s = "Polynom2";
	Polynom A;
	A.loadString(tm[0]);
	Polynom B;
	B = A;
	row r;
	r.data = &A;
	r.key = s;
	USTable H;
	H.Insert(r);
	EXPECT_EQ(B, *H.Search(s));

}

TEST(USTable, can_not_find_a_missing_polynom)
{
	string tm[5];

	for (int i = 0; i < 3; i++) {
		tm[i] = "x^";
		tm[i] += to_string(i + 1);
		tm[i] += "y^";
		tm[i] += to_string(i + 1);
		tm[i] += "z^";
		tm[i] += to_string(i + 1);
	}
	string s = "Polynom3";
	string s1 = "Polynom4";
	Polynom A(tm[0]);
	row r;
	r.data = &A;
	r.key = s;
	USTable H;
	H.Insert(r);
	EXPECT_EQ(NULL, H.Search(s1));
}

TEST(USTable, can_delete_a_polynom)
{
	string tm[5];

	for (int i = 0; i < 3; i++) {
		tm[i] = "x^";
		tm[i] += to_string(i + 1);
		tm[i] += "y^";
		tm[i] += to_string(i + 1);
		tm[i] += "z^";
		tm[i] += to_string(i + 1);
	}

	string s = "Polynom4";

	Polynom A(tm[0]);
	Polynom B;
	B = A;
	row r;
	r.data = &A;
	r.key = s;
	USTable H;
	H.Insert(r);
	EXPECT_EQ(B, *H.Search(s));
	H.Delete(s);
	EXPECT_EQ(NULL, H.Search(s));
}