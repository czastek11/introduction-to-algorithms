#include <iostream>
#include "F-losujace.h"
#include <vector>
using namespace std;

string male_l(string Word)
{
	for (unsigned int i = 0; i < Word.length(); i++)
	{
		Word[i] = tolower(Word[i]);
	}
	return Word;
}

template <typename typ>
typ najm(typ a, typ b, typ c,int & por)
{
	por++;
	if (a <= b)
	{
		por++;
		if (c <= a) return c;
		else return a;
	}
	else
	{
		por++;
		if (c <= b) return c;
		else return b;
	}
}

template <typename typ>
void Merge_3(vector<typ> & A, unsigned int p, unsigned int s1,unsigned int s2, unsigned int k,int & por ,int & przyp)
{
	unsigned int ln = s1 - p + 1;
	unsigned int mn = s2 - s1;
	unsigned int pn = k - s2;
	vector<typ> L;
	vector<typ> M;
	vector<typ> P;
	for (unsigned int i = 0; i < ln; i++) L.push_back(A.at(p + i));
	for (unsigned int i = 0; i < mn; i++) M.push_back(A.at(s1 + i+1));
	for (unsigned int i = 0; i < pn; i++) P.push_back(A.at(s2 + 1 + i));
	L.push_back(numeric_limits<typ>::max());
	M.push_back(numeric_limits<typ>::max());
	P.push_back(numeric_limits<typ>::max());
	przyp += ln + mn + pn + 3;
	unsigned int i = 0, j = 0, h = 0, n = p;
	while (n <= k)
	{
		if (najm(L.at(i), M.at(j), P.at(h),por) == L.at(i))
		{
			A.at(n) = L.at(i);
			przyp++;
			i++;
		}
		else if (najm(L.at(i), M.at(j), P.at(h),por) == M.at(j))
		{
			A.at(n) = M.at(j);
			przyp++;
			j++;
		}
		else
		{
			A.at(n) = P.at(h);
			przyp;
			h++;
		}
		n++;
	}
}

void Merge_3(vector<string>& A, unsigned int p, unsigned int s1, unsigned int s2, unsigned int k,int & por,int & przyp)
{
	unsigned int ln = s1 - p + 1;
	unsigned int mn = s2 - s1;
	unsigned int pn = k - s2;
	vector<string> L;
	vector<string> M;
	vector<string> P;
	for (unsigned int i = 0; i < ln; i++) L.push_back(A.at(p + i));
	for (unsigned int i = 0; i < mn; i++) M.push_back(A.at(s1 + i + 1));
	for (unsigned int i = 0; i < pn; i++) P.push_back(A.at(s2 + 1 + i));
	L.push_back("~~~~~~~~~~~~~~");
	M.push_back("~~~~~~~~~~~~~~");
	P.push_back("~~~~~~~~~~~~~~");
	przyp += ln + mn + pn + 3;
	unsigned int i = 0, j = 0, h = 0, n = p;
	while (n <= k)
	{
		if (najm(L.at(i), M.at(j), P.at(h),por) == L.at(i))
		{
			A.at(n) = L.at(i);
			przyp++;
			i++;
		}
		else if (najm(L.at(i), M.at(j), P.at(h),por) == M.at(j))
		{
			A.at(n) = M.at(j);
			przyp++;
			j++;
		}
		else
		{
			A.at(n) = P.at(h);
			przyp++;
			h++;
		}
		n++;
	}
}

template <typename typ>
void MERGESORT_3(vector<typ> & A, unsigned int p, unsigned int k,int & por, int & przyp)
{
	unsigned int s,s1,s2;
	if (k - p == 1)
	{
		por++;
		if (A.at(k) < A.at(p))
		{
			typ pom;
			pom = A.at(k);
			A.at(k) = A.at(p);
			A.at(p) = pom;
			przyp+=3;
		}
	}
	else if (p < k)
	{
		s = (k-p) / 3;
		s1 = p + s;
		s2 = p + 2*s+1;
		MERGESORT_3(A, p, s1, por, przyp);
		MERGESORT_3(A,s1+1 ,s2, por, przyp);
		MERGESORT_3(A,s2+1, k, por, przyp);
		Merge_3(A, p, s1, s2, k, por, przyp);
	}
}

int main()
{
	
	cout << "Podaj wielkosc tablicy" <<endl;
	unsigned int n;
	cin >> n;
	cout << "Podaj rodzaj danych" << endl;
	string type;
	cin >> type;
	cout << "Wprowadz dane:\n";
	bool err;
	int por = 0, przyp = 0;
	if (type == "int")
	{
		vector<int> Tab;
		for (int i = 0; i < n; i++)
		{
			int pom;
			cin >> pom;
			Tab.push_back(pom);
		}
		cout << "\n0\n\n";
		MERGESORT_3(Tab, 0, n - 1,por,przyp);
		cout << "Posortowana tablica\n";
		for (int i = 0; i < Tab.size(); i++) cerr << Tab.at(i) << '\n';
		cerr << '\n' << "Ilosc porownan : " << por << " Ilosc przypisan : " << przyp << endl;

	}
	else if (type == "float")
	{
		vector<double> Tab;
		for (int i = 0; i < n; i++)
		{
			double pom;
			cin >> pom;
			Tab.push_back(pom);
		}
		cout << "\n0\n\n";
		MERGESORT_3(Tab, 0, n - 1, por, przyp);
		cout << "Posortowana tablica\n";
		for (int i = 0; i < Tab.size(); i++) cerr << Tab.at(i) << '\n';
		cerr << '\n' << "Ilosc porownan : " << por << " Ilosc przypisan : " << przyp << endl;
	}
	else if (type == "string")
	{
		vector<string> Tab;
		for (int i = 0; i < n; i++)
		{
			string pom;
			cin >> pom;
			Tab.push_back(male_l(pom));
		}
		cout << "\n0\n\n";
		cout << "Posortowana tablica\n";
		MERGESORT_3(Tab, 0, n - 1, por, przyp);
		for (int i = 0; i < Tab.size(); i++) cerr << Tab.at(i) << '\n';
		cerr << '\n' << "Ilosc porownan : " << por << " Ilosc przypisan : " << przyp << endl;
	}
	else
	{
		cout <<"nieprawid³owy typ danych"<< endl;
		err = true;
	}
	return 0;
}