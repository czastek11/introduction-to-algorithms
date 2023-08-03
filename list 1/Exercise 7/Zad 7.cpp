#include <iostream>
#include "F-losujace.h"
#include <fstream>

using namespace std;

void Insert_Sort(double* A, unsigned int n, unsigned int& comp, unsigned int& alloc)
{

	int j;
	comp = 0;
	alloc = 0;
	double x;

	for (int i = n-2; i >=0; i--)
	{
		x = A[i];
		alloc++;
		j = i + 1;
		while (j <n)
		{
			comp++;
			if (A[j] < x)
			{
				A[j - 1] = A[j];
				alloc++;
				j++;
			}
			else break;
		}
		A[j - 1] = x;
		alloc++;
	}
}

int main()
{
	//fstream out;
	//out.open("out.csv", ios::out);
	unsigned int n;
	cin >> n;
	unsigned int por = 0, przyp = 0;
	double* AR = new double[n];
	for (int i = 0; i < n; i++)
	{
		AR[i] = rand2(-100.0, 100.0);
		cerr << AR[i] << " ";
	}
	cout << endl;
	Insert_Sort(AR, n, por, przyp);
	for (int i = 0; i < n; i++)
	{
		cerr << AR[i] << " ";
	}
	cout << endl << por << " " << przyp << endl;
	delete[] AR;
	//out  << por << ";" << przyp << endl;
}