#pragma once
#include"Table.h"


class STable : public Table
{
private:
	vector<row> v;
	int Binary_search(string&);
public:
	STable();
	~STable() {}
	void Insert(row&);
	void Delete(string&);
	Polynom *Search(string&);
};

