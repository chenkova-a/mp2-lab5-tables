#include "stdafx.h"
#include"Hash-table.h"

unsigned int HTable::Hash2(string& _key) {
	{
		unsigned int len = _key.size();
		const unsigned int m = 0x5bd1e995;
		const unsigned int seed = 0;
		const int r = 24;

		unsigned int h = seed ^ len;

		const unsigned char * data = (const unsigned char *)_key.c_str();
		unsigned int k;

		while (len >= 4)
		{
			k = data[0];
			k |= data[1] << 8;
			k |= data[2] << 16;
			k |= data[3] << 24;

			k *= m;
			k ^= k >> r;
			k *= m;

			h *= m;
			h ^= k;

			data += 4;
			len -= 4;
		}
		switch (len)
		{
		case 3:
			h ^= data[2] << 16;
		case 2:
			h ^= data[1] << 8;
		case 1:
			h ^= data[0];
			h *= m;
		};

		h ^= h >> 13;
		h *= m;
		h ^= h >> 15;

		return h % 1024;
	}
}

HTable::HTable() {
	vector<list<row>> temp(1024);
	v = temp;
	list<row>a;
	for (int i = 0; i < 1024; i++)
		v[i] = a;
	counter = 0;
}

void HTable::Insert(row& str) {
	counter = 0;
	unsigned int h = Hash2(str.key);
	if (!v[h].empty())
		for (auto it = v[h].begin(); it != v[h].end(); it++, counter++) {
			if ((*it).key == str.key) {
				cout << "This key is taken in Hash-Table" << endl;
				return;
			}
		}
	v[h].push_back(str);
	counter++;
}

void HTable::Delete(string&_key) {
	counter = 0;
	unsigned int h = Hash2(_key);
	for (auto it = v[h].begin(); it != v[h].end(); it++, counter++) {
		if ((*it).key == _key) {
			v[h].erase(it);
			break;
		}
	}
}

Polynom* HTable::Search(string&_key) {
	counter = 0;
	unsigned int h = Hash2(_key);
	for (auto it = v[h].begin(); it != v[h].end(); it++, counter++) {
		if ((*it).key == _key)
			return (*it).data;
	}
	return NULL;
}