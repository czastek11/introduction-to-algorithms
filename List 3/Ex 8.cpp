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
		if (A.at(i) < A.at(i - 1))
		{
			return 0;
		}
	}
	return 1;
}

void _Heapify_(vector<int>& A, unsigned int i, unsigned int n, unsigned int k)
{
	unsigned int w = i;
	vector<unsigned int> indeksy;
	for (unsigned int j = 0; j < k; j++) indeksy.push_back(k * i + j + 1);
	for (unsigned int j = 0; j < k; j++)
	{
		if (indeksy.at(j) < n && A.at(indeksy.at(j)) > A.at(w))w = indeksy.at(j);
	}
	if (w != i)
	{
		swap(A.at(i), A.at(w));
		_Heapify_(A, w, n,k);
	}
}

void _Heapsort_(vector<int>& A, unsigned int k)
{
	unsigned int n = A.size();
	for (int i = (n - 1) / k; i >= 0; i--) _Heapify_(A, i, n, k);
	for (int i = n - 1; i >= 1; i--)
	{
		swap(A.at(i), A.at(0));
		n--;
		_Heapify_(A, 0, n, k);
	}
}


int main()
{
	fstream plik1, plik2;
	vector<int> kloc, klocuch;
	srand(time(NULL));
	int n, pom;
	for (unsigned int l = 2; l < 20; l++)
	{
		for (int j = 0; j < 1000; j++)
		{
			kloc.clear();
			n = rand() % 60 + 1;
			for (int k = 0; k < n; k++)
			{
				kloc.push_back(rand() % 41);
			}
			_Heapsort_(kloc, l);
			if (!check_sort(kloc))
			{
				cout << "zly case " << j << endl;
				for (int k = 0; k < n; k++) cout << kloc.at(k) << " ";
				break;
			}
		}
	}
	for (int k = 0; k < n; k++) cout << kloc.at(k) << " ";
	
	return 0;
}