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
void Merge(vector<typ> & A, unsigned int p, unsigned int s, unsigned int k, int & por , int & przyp)
{
	unsigned int ln = s - p + 1;
	unsigned int pn = k - s;
	vector<typ> L;
	vector<typ> P;
	for (unsigned int i = 0; i < ln; i++) L.push_back(A.at(p + i));
	for (unsigned int i = 0; i < pn; i++) P.push_back(A.at(s + 1 + i));
	L.push_back(numeric_limits<typ>::max());
	P.push_back(numeric_limits<typ>::max());
	przyp += ln + pn + 2;
	unsigned int i=0, j=0, n=p;
	while (n <= k)
	{
		por++;
		if (L.at(i) < P.at(j))
		{
			A.at(n) = L.at(i);
			przyp++;
			i++;
		}
		else
		{
			A.at(n) = P.at(j);
			przyp++;
			j++;
		}
		n++;
	}
}

void Merge(vector<string>& A, unsigned int p, unsigned int s, unsigned int k,int & por, int & przyp)
{
	unsigned int ln = s - p + 1;
	unsigned int pn = k - s;
	vector<string> L;
	vector<string> P;
	for (unsigned int i = 0; i < ln; i++) L.push_back(A.at(p + i));
	for (unsigned int i = 0; i < pn; i++) P.push_back(A.at(s + 1 + i));
	L.push_back("~~~~~~~~~~~~~~~~~~");
	P.push_back("~~~~~~~~~~~~~~~~~~");
	przyp += ln + pn + 2;
	unsigned int i = 0, j = 0, n = p;
	while (n <= k)
	{
		por++;
		if (L.at(i) < P.at(j))
		{
			A.at(n) = L.at(i);
			przyp++;
			i++;
		}
		else
		{
			A.at(n) = P.at(j);
			przyp++;
			j++;
		}
		n++;
	}
}

template <typename typ>
void MERGESORT(vector<typ> & A, unsigned int p, unsigned int k, int & por, int & przyp)
{
	unsigned int s;
	if (p < k)
	{
		s = (p + k) / 2;
		MERGESORT(A, p, s,por,przyp);
		MERGESORT(A, s + 1, k,por,przyp);
		Merge(A, p, s, k,por,przyp);
	}
}

int main()
{
	cout << "Podaj wielkosc tablicy" << endl;
	unsigned int n;
	cin >> n;
	cout << "Podaj rodzaj danych" << endl;
	string type;
	cin >> type;
	bool err;
	int por=0, przyp=0;
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
		MERGESORT(Tab, 0, n - 1,por,przyp);
		cout << "posortowana tablica:\n\n";
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
		MERGESORT(Tab, 0, n - 1,por,przyp);
		cout << "posortowana tablica:\n\n";
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
		MERGESORT(Tab, 0, n - 1, por, przyp);
		cout << "posortowana tablica:\n\n";
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