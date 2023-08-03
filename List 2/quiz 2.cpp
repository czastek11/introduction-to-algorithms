#include <iostream>
#include <vector>
using namespace std;


void Merge(vector<int> & A, unsigned int p, unsigned int s, unsigned int k, int & por , int & przyp)
{
	unsigned int ln = s - p + 1;
	unsigned int pn = k - s;
	vector<int> L;
	vector<int> P;
	for (unsigned int i = 0; i < ln; i++) L.push_back(A.at(p + i));
	for (unsigned int i = 0; i < pn; i++) P.push_back(A.at(s + 1 + i));
	L.push_back(99999999);
	P.push_back(99999999);
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


void MERGESORT(vector<int> & A, unsigned int p, unsigned int k, int & por, int & przyp)
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

int najm(int a, int b, int c,int d,int & por)
{
    int pom=a;
    por++;
	if(pom>b) pom=b;
	por++;
	if(pom>c) pom=c;
	por++;
	if(pom>d) pom=d;
	return pom;
}

void Merge_4(vector<int> & A, unsigned int p, unsigned int s1,unsigned int s2,unsigned int s3, unsigned int k, int & por , int & przyp)
{
	unsigned int ln = s1 - p + 1;
	unsigned int s1n= s2-s1;
	unsigned int s2n=s3-s2;
	unsigned int pn = k - s3;
	vector<int> L;
	vector<int> S1;
	vector<int> S2;
	vector<int> P;
	for (unsigned int i = 0; i < ln; i++) L.push_back(A.at(p + i));
	for (unsigned int i = 0; i < s1n; i++) S1.push_back(A.at(s1+1 + i));
	for (unsigned int i = 0; i < s2n; i++) S2.push_back(A.at(s2+1 + i));
	for (unsigned int i = 0; i < pn; i++) P.push_back(A.at(s3 + 1 + i));
	L.push_back(99999999);
	S1.push_back(99999999);
	S2.push_back(99999999);
	P.push_back(99999999);
	przyp += ln + pn+s1n+s2n + 4;
	unsigned int i=0, j=0,g=0,h=0, n=p;
	while (n <= k)
	{
		por++;
		if (najm(L.at(i), S1.at(j), S2.at(g),P.at(h),por) == L.at(i))
		{
			A.at(n) = L.at(i);
			przyp++;
			i++;
		}
		else if (najm(L.at(i), S1.at(j), S2.at(g),P.at(h),por) == S1.at(j))
		{
			A.at(n) = S1.at(j);
			przyp++;
			j++;
		}
		else if (najm(L.at(i), S1.at(j), S2.at(g),P.at(h),por) == S2.at(g))
		{
			A.at(n) = S2.at(g);
			przyp++;
			g++;
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

void MERGESORT_4(vector<int> & A, unsigned int p, unsigned int k, int & por, int & przyp)
{
	unsigned int s1,s2,s3;
	s1 = (k - p) * 1 / 4 + p;
	s2= (k - p) * 2 / 4 + p;
	s3= (k - p) * 3 / 4 + p;
	if(k-p==1)
    {
        por++;
		if (A.at(k) < A.at(p))
		{
			int pom;
			pom = A.at(k);
			A.at(k) = A.at(p);
			A.at(p) = pom;
			przyp+=3;
		}
    }
    else if(k-p==2)
    {
        por++;
		if (A.at(k) < A.at(p))
		{
			int pom;
			pom = A.at(k);
			A.at(k) = A.at(p);
			A.at(p) = pom;
			przyp+=3;
		}
		por++;
		if(A.at(p+1) < A.at(p))
        {
            int pom;
			pom = A.at(p+1);
			A.at(p+1) = A.at(p);
			A.at(p) = pom;
			przyp+=3;
        }
        else if(A.at(k) < A.at(p+1))
        {
            int pom;
			pom = A.at(k);
			A.at(k) = A.at(p+1);
			A.at(p+1) = pom;
			przyp+=3;
        }
    }
    else if(k-p>2)
	{
		MERGESORT_4(A, p, s1,por,przyp);
		MERGESORT_4(A, s1+1, s2,por,przyp);
		MERGESORT_4(A, s2+1, s3,por,przyp);
		MERGESORT_4(A, s3+1, k,por,przyp);
		Merge_4(A, p, s1,s2,s3, k,por,przyp);
	}
}


int main()
{
	cout << "Podaj wielkosc tablicy" << endl;
	unsigned int n;
	cin >> n;
	bool err;
	int por=0, przyp=0,por2=0,przyp2=0;

		vector<int> Tab1;
		vector<int> Tab2;
		for (int i = 0; i < n; i++)
		{
			int pom;
			cin >> pom;
			Tab1.push_back(pom);
			Tab2.push_back(pom);
		}
		cout << "\n0\n\n";
		MERGESORT(Tab1, 0, n - 1,por,przyp);
		MERGESORT_4(Tab2, 0, n - 1,por2,przyp2);
		cout << "posortowana tablica:\n\n";
		for (int i = 0; i < Tab1.size(); i++) cerr << Tab1.at(i) << '\n';
		cerr << '\n' << "Ilosc porownan : " << por << " Ilosc przypisan : " << przyp << endl;
		cout << "posortowana tablica:\n\n";
		for (int i = 0; i < Tab2.size(); i++) cerr << Tab2.at(i) << '\n';
		cerr << '\n' << "Ilosc porownan : " << por2 << " Ilosc przypisan : " << przyp2 << endl;


	return 0;
}
