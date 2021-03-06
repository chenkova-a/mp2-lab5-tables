//// Tables.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include"../Tables/Table.h"
#include"../Tables/Polynoms.h"
#include"../Tables/Hash-table.h"
#include"../Tables/Unsorted-table.h"
#include"../Tables/Sorted-table.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	int k = 0;
	int	l;
	bool flag;
	int it = 0;
	int counter;
	string s, s1, s2;
	double c;
	Polynom A, B, C, A1, A2, B1, B2, C1;
	vector<Polynom>v(1024);
	HTable H;
	STable S;
	USTable U;
	do {
		cout << '\n' << "Choose one of the items:" << '\n';
		string d[5];
		d[0] = "1. Search a Polynom";
		d[1] = "2. Insert a Polynom";
		d[2] = "3. Delete a Polynom";
		d[3] = "4. Operations with polynomials";
		d[4] = "5. Exit";
		for (int i = 0; i < 5; i++)
			cout << d[i] << '\n';
		cout << "Input a menu number:";
		cin >> k;

		if (k == 5) break;
		switch (k) {
		case 1: {
			cout << "Input a name of the polynom" << endl;
			cin >> s;
			if (H.Search(s) != NULL) {
				A = *H.Search(s);
				cout << '\n';
				A.Print();
			}
			else
				cout << "There is not such polynom in Hash-Table" << endl;
			if (S.Search(s) != NULL) {
				A1 = *S.Search(s);
				cout << '\n' ;
				A1.Print();
			}
			else
				cout << "There is not such polynom in Ordered Table" << endl;
			if (U.Search(s) != NULL) {
				A2 = *U.Search(s);
				cout << '\n';
				A2.Print();
			}
			else
				cout << "There is not such polynom in Disordered Table" << endl;
			cout << '\n' << "Number of operations to search a polynom in Hash-Table = " << H.Count();
			cout << '\n' << "Number of operations to search a polynom in Ordered Table = " << S.Count();
			cout << '\n' << "Number of operations to search a polynom in Disordered Table = " << U.Count() << endl;
			break;
		}
		case 2: {

			cout << "Input a name of the polynom" << endl;
			cin >> s;
			cout << "Input polynom" << '\n';
			string t;
			cin >> t;
			Polynom A(t);
			v[it].loadString(t);
			row r;
			r.data = &v[it];
			r.key = s;
			H.Insert(r);
			S.Insert(r);
			U.Insert(r);
			it++;
			cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
			cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << S.Count();
			cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << U.Count() << endl;
			break;
		}
		case 3: {
			cout << "Input a name of the polynom" << endl;
			cin >> s;
			H.Delete(s);
			S.Delete(s);
			U.Delete(s);
			cout << '\n' << "Number of operations to delete a polynom in Hash-Table = " << H.Count();
			cout << '\n' << "Number of operations to delete a polynom in Ordered Table = " << S.Count();
			cout << '\n' << "Number of operations to delete a polynom in Disordered Table = " << U.Count() << endl;
			break;
		}
		case 4: {
			int f = 0;
			flag = true;
			do {
				string g[2];
				g[0] = "1. Input polynomials";
				g[1] = "2. Polynomials from tables";
				for (int i = 0; i <2; i++)
					cout << g[i] << '\n';
				cout << "Input a menu number:";
				cin >> f;
			} while ((f != 1) && (f != 2));
			if (f == 1) {
				cout << "Input a name of the polynom" << endl;
				cin >> s;
				cout << "Input polynom" << '\n';
				string t;
				cin >> t;
				v[it].loadString(t);
				A = v[it];
				row r;
				r.data = &v[it];
				r.key = s;
				H.Insert(r);
				S.Insert(r);
				U.Insert(r);
				it++;
				cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
				cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << S.Count();
				cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << U.Count() << endl;
				cout << "Input a name of the polynom" << endl;
				cin >> s1;
				cout << "Input polynom" << '\n';
				t = "";
				cin >> t;
				v[it].loadString(t);
				B = v[it];
				row r1;
				r1.data = &v[it];
				r1.key = s1;
				H.Insert(r1);
				S.Insert(r1);
				U.Insert(r1);
				it++;
				cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
				cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << S.Count();
				cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << U.Count() << endl;
			}
			if (f == 2) {
				cout << "Input a name of the polynom" << endl;
				cin >> s;
				if (H.Search(s) != NULL) {
					A = *H.Search(s);
					cout << '\n' ;
					A.Print();
				}
				else {
					cout << "There is not such polynom in Hash-Table" << endl;
					flag = false;
				}
				if (S.Search(s) != NULL) {
					A1 = *S.Search(s);
					cout << '\n' ;
					A1.Print();
				}
				else {
					cout << "There is not such polynom in Ordered Table" << endl;
					flag = false;
				}
				if (U.Search(s) != NULL) {
					A2 = *U.Search(s);
					cout << '\n';
					A2.Print();
				}
				else {
					cout << "There is not such polynom in Disordered Table" << endl;
					flag = false;
				}
				cout << '\n' << "Number of operations to search a polynom in Hash-Table = " << H.Count();
				cout << '\n' << "Number of operations to search a polynom in Ordered Table = " << S.Count();
				cout << '\n' << "Number of operations to search a polynom in Disordered Table = " << U.Count() << endl;
				cout << "Input a name of the polynom" << endl;
				cin >> s1;
				if (H.Search(s1) != NULL) {
					B = *H.Search(s1);
					cout << '\n' ;
					B.Print();
				}
				else {
					cout << "There is not such polynom in Hash-Table" << endl;
					flag = false;
				}
				if (S.Search(s1) != NULL) {
					B1 = *S.Search(s1);
					cout << '\n' ;
					B1.Print();
				}
				else {
					cout << "There is not such polynom in Ordered Table" << endl;
					flag = false;
				}
				if (U.Search(s1) != NULL) {
					B2 = *U.Search(s1);
					cout << '\n';
					B2.Print();
				}
				else {
					cout << "There is not such polynom in Disordered Table" << endl;
					flag = false;
				}
				cout << '\n' << "Number of operations to search a polynom in Hash-Table = " << H.Count();
				cout << '\n' << "Number of operations to search a polynom in Ordered Table = " << S.Count();
				cout << '\n' << "Number of operations to search a polynom in Disordered Table = " << U.Count() << endl;
			}
			if (flag) {
				l = 0;
				while (l < 5) {
					string e[5];
					e[0] = "1. A+B=";
					e[1] = "2. A-B=";
					e[2] = "3. B-A=";
					e[3] = "4. A*B=";
					e[4] = "5. Exit";
					for (int i = 0; i < 5; i++)
						cout << e[i] << '\n';
					cout << "Input a menu number:";
					cin >> l;
					switch (l) {
					case 1: {
						v[it] = A + B;
						row r2;
						r2.data = &v[it];
						cout << "Input a name of polynom A+B" << endl;
						cin >> s2;
						r2.key = s2;
						H.Insert(r2);
						S.Insert(r2);
						U.Insert(r2);
						cout << v[it].print() << '\n';
						it++;
						cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
						cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << S.Count();
						cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << U.Count() << endl;
						break;
					}
					case 2: {
						v[it] = A - B;
						row r2;
						r2.data = &v[it];
						cout << "Input a name of polynom A-B" << endl;
						cin >> s2;
						r2.key = s2;
						H.Insert(r2);
						S.Insert(r2);
						U.Insert(r2);
						cout << v[it].print() << '\n';
						it++;
						cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
						cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << S.Count();
						cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << U.Count() << endl;
						break;
					}
					case 3: {
						v[it] = B - A;
						row r2;
						r2.data = &v[it];
						cout << "Input a name of polynom B-A" << endl;
						cin >> s2;
						r2.key = s2;
						H.Insert(r2);
						S.Insert(r2);
						U.Insert(r2);
						cout << v[it].print() << '\n';
						it++;
						cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
						cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << S.Count();
						cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << U.Count() << endl;
						break;
					}
					case 4: {
						v[it] = A * B;
						row r2;
						r2.data = &v[it];
						cout << "Input a name of polynom A*B" << endl;
						cin >> s2;
						r2.key = s2;
						H.Insert(r2);
						S.Insert(r2);
						U.Insert(r2);
						cout << v[it].print() << '\n';
						it++;
						cout << '\n' << "Number of operations to insert a polynom in Hash-Table = " << H.Count();
						cout << '\n' << "Number of operations to insert a polynom in Ordered Table = " << S.Count();
						cout << '\n' << "Number of operations to insert a polynom in Disordered Table = " << U.Count() << endl;
						break;
					}
					}
				}
			}
			break;
		}
		}
	} while (k < 5);
}
