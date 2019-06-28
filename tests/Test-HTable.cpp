#include"../Tables/Table.h"
#include"../gtest/gtest.h"
#include "../Tables/Hash-table.h" 
struct tp {
	int c;
	double d;
};
TEST(HTable, can_create_a_table)
{
	ASSERT_NO_THROW(HTable A);
}

TEST(HTable, can_insert_a_row)
{
	HTable H;
	Polynom A;
	row r;
	r.data = &A;
	r.key = "Polynom1";
	ASSERT_NO_THROW(H.Insert(r));
}

TEST(HTable, can_find_a_polynom)
{
	string tm[5];
	Polynom M[5];
	HTable H;
	row r;
	string s;

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

	Polynom B;

	B = M[0];

	EXPECT_EQ(B, *H.Search(s));

}

TEST(HTable, can_not_find_a_missing_polynom)
{
	string s;
	string tm[5];
	Polynom M[5];
	HTable H;
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

	string s1 = "Polynom5";

	EXPECT_EQ(NULL, H.Search(s1));
}

TEST(HTable, can_delete_a_polynom)
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
	HTable H;
	H.Insert(r);
	EXPECT_EQ(B, *H.Search(s));
	H.Delete(s);
	EXPECT_EQ(NULL, H.Search(s));
}