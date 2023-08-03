#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <fstream>

using namespace std;

bool check_sort(vector<int> A)
{
	for (unsigned int i = 1; i < A.size(); i++)
	{
		if (A.at(i) < A.at(i-1))
		{
			return 0;
		}
	}
	return 1;
}

void Heapify(vector<int> & A,unsigned int i,unsigned int n)
{
	unsigned int l = 2 * i + 1, r = 2 * i + 2, w = i;
	if (l<n && A.at(l)>A.at(w)) w = l;
	if (r<n && A.at(r)>A.at(w)) w = r;
	if (w != i)
	{
		swap(A.at(i), A.at(w));
		Heapify(A, w, n);
	}
}

void Heapify(vector<int>& A, unsigned int i, unsigned int n,unsigned int & por, unsigned int& przyp,unsigned int & pam, unsigned int sumpam)
{
	unsigned int sumpam2=sumpam;
	unsigned int l = 2 * i + 1, r = 2 * i + 2, w = i;
	sumpam2 += sizeof(unsigned int)*3;
	por++;
	if (l<n && A.at(l)>A.at(w)) w = l;
	por++;
	if (r<n && A.at(r)>A.at(w)) w = r;
	if (w != i)
	{
		swap(A.at(i), A.at(w));
		przyp += 3;
		Heapify(A, w, n,por,przyp,pam,sumpam2);
	}
	if (sumpam2 > pam) pam = sumpam2;
}

void Heapsort(vector<int>& A)
{
	unsigned int n = A.size();
	for ( int i = (n-1) / 2; i >= 0; i--) Heapify(A, i,n);
	for ( int i =n-1; i >= 1; i--)
	{
		swap(A.at(i), A.at(0));
		n--;
		Heapify(A, 0, n);
	}
}

void Heapsort(vector<int>& A, unsigned int& por, unsigned int& przyp, unsigned int& pam)
{
	pam = 0;
	unsigned int sumpam = 0;
	unsigned int n = A.size();
	sumpam += sizeof(unsigned int);
	//sumpam += sizeof(int)*A.size();
	for (int i = (n - 1) / 2; i >= 0; i--) Heapify(A, i, n, por, przyp, pam,sumpam);
	for (int i = n - 1; i >= 1; i--)
	{
		swap(A.at(i), A.at(0));
		przyp += 3;
		n--;
		Heapify(A, 0, n, por, przyp, pam,sumpam);
	}
	if (sumpam > pam) pam = sumpam;
}

void Heapify3(vector<int>& A, unsigned int i, unsigned int n)
{
	unsigned int l = 3 * i + 1, c = 3 * i + 2, r = 3 * i + 3, w = i;
	if (l<n && A.at(l)>A.at(w)) w = l;
	if (c<n && A.at(c)>A.at(w)) w = c;
	if (r<n && A.at(r)>A.at(w)) w = r;
	if (w != i)
	{
		swap(A.at(i), A.at(w));
		Heapify3(A, w, n);
	}
}

void Heapify3(vector<int>& A, unsigned int i, unsigned int n, unsigned int& por, unsigned int& przyp, unsigned int& pam, unsigned int sumpam)
{
	unsigned int l = 3 * i + 1, c = 3 * i + 2, r = 3 * i + 3, w = i;
	unsigned int sumpam2 = sumpam;
	sumpam2 += sizeof(unsigned int) * 4;
	por+=3;
	if (l<n && A.at(l)>A.at(w)) w = l;
	if (c<n && A.at(c)>A.at(w)) w = c;
	if (r<n && A.at(r)>A.at(w)) w = r;
	if (w != i)
	{
		swap(A.at(i), A.at(w));
		przyp += 3;
		Heapify3(A, w, n, por, przyp, pam,sumpam2);
	}
	if (sumpam2 > pam) pam = sumpam2;
}

void Heapsort3(vector<int>& A)
{
	unsigned int n = A.size();
	for (int i = (n-1)/3; i >= 0; i--) Heapify3(A, i, n);
	for (int i = n - 1; i >= 1; i--)
	{
		swap(A.at(i), A.at(0));
		n--;
		Heapify3(A, 0, n);
	}
}

void Heapsort3(vector<int>& A, unsigned int& por, unsigned int& przyp, unsigned int& pam)
{
	pam = 0;
	unsigned int sumpam = 0;
	unsigned int n = A.size();
	sumpam += sizeof(unsigned int);
	//sumpam += sizeof(int) * A.size();
	for (int i = (n - 1) / 3; i >= 0; i--) Heapify3(A, i, n,por,przyp,pam,sumpam);
	for (int i = n - 1; i >= 1; i--)
	{
		swap(A.at(i), A.at(0));
		przyp += 3;
		n--;
		Heapify3(A, 0, n,por,przyp,pam,sumpam);
	}
	if (sumpam > pam) pam = sumpam;
}



int main()
{
	fstream plik1, plik2;
	vector<int> kloc,klocuch;
	srand(time(NULL));
	int n,pom;
	/*
	for (int j = 0; j < 1000; j++)
	{
		kloc.clear();
		n = rand() % 20 + 1;
		for (int k = 0; k <n ; k++)
		{
			kloc.push_back(rand() % 41);
		}
		Heapsort(kloc);
		if (!check_sort(kloc))
		{
			cout << "zly case " << j << endl;
			for (int k = 0; k < n; k++) cout << kloc.at(k) << " ";
			break;
		}
	}
	for (int j = 0; j < 1000; j++)
	{
		kloc.clear();
		n =rand() % 40 + 1;
		for (int k = 0; k < n; k++)
		{
			kloc.push_back(rand() % 41);
		}
		Heapsort3(kloc);
		if (!check_sort(kloc))
		{
			cout << "zly case " << j << endl;
			for (int k = 0; k < n; k++) cout << kloc.at(k) << " ";
			break;
		}
	}
	*/
	kloc.clear();
	klocuch.clear();
	plik1.open("HEAP_1.data", std::ios::out);
	plik2.open("HEAP_3.data", std::ios::out);
	unsigned int por1=0, przyp1=0, pam1=0, por2 = 0, przyp2 = 0, pam2 = 0;
	for(int i = 100; i <= 2000; i+=50)
	{ 
		por1 = 0, przyp1 = 0, pam1 = 0, por2 = 0, przyp2 = 0, pam2 = 0;
		for (int j = 0; j < i; j++)
		{
			pom = rand() % 101;
			kloc.push_back(pom);
			klocuch.push_back(pom);
		}
		Heapsort(kloc, por1, przyp1, pam1);
		Heapsort3(klocuch, por2, przyp2, pam2);
		if (!check_sort(kloc) || !check_sort(klocuch)) cout << "error" << endl;
		else
		{
			cout << i << " " << por1 << " " << przyp1 << " " << pam1 << endl;
			plik1 << i << " " << por1 << " " << przyp1 << " " << pam1 << endl;
			cout << i << " " << por2 << " " << przyp2 << " " << pam2 << endl;
			plik2<< i << " " << por2 << " " << przyp2 << " " << pam2 << endl;

		}
	}
	return 0;
}