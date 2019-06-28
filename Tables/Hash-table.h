
#pragma once
#include "Table.h"
#include<list>
#include <math.h>
class HTable : public Table
{
private:
	vector<list<row>> v;
	unsigned int Hash2(string&);
public:
	HTable();
	~HTable() {}
	void Insert(row&);
	void Delete(string&);
	Polynom* Search(string&);
};

