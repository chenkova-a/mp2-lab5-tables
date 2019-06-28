#pragma once
#include"Table.h"


class USTable : public Table
{
private:
	vector<row> v;
public:
	USTable();
	~USTable() {}
	void Insert(row&);
	void Delete(string&);
	Polynom* Search(string&);
};

