#include <iostream>
#include "F-losujace.h"
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

void Swap(double & x, double & y)
{
	double pom = x;
	x = y;
	y = pom;
}

void Insert_2_Sort(double* A, unsigned int n, unsigned int & comp, unsigned int & alloc)
{
	comp = 0;
	alloc = 0;
	int mod = 2;
	int j, pom1, pom2 , k;
	double x, y;
	if (n % 2 == 0)
	{
		mod = 3;
		comp++;
		if (A[1] < A[0])
		{
			swap(A[1], A[0]);
			alloc += 3;
		}
	}
	for (int i = mod; i < n; i += 2)
	{
		comp++;
		if (A[i] < A[i-1])
		{
			swap(A[i], A[i-1]);
			alloc += 3;
		}
		j = i - 2;
		x = A[i];
		y = A[i - 1];
		alloc += 2;
		pom1 = i;
		pom2 = i - 1;
		while (j >= 0)
		{
			comp++;
			if (A[j] > x)
			{
				A[j + 2] = A[j];
				A[j] = y;
				alloc++;
				pom1 = j + 1;
				pom2 = j;
				j--;
			}
			else if (A[j] > y)
			{
				comp++;
				k = j;
				do
				{
					if(A[k]>y)
					{
						comp++;
						A[k + 1] = A[k];
						alloc++;
						pom2 = k;
						k--;
					}
					else
					{
						comp++;
						break;
					}
				} 
				while (k >= 0);
				break;
			}
			else
			{
				comp++;
				break;
			}
		}
		A[pom1] = x;
		A[pom2] = y;
		alloc += 2;
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
		AR[i] = rand2(-100.0, 100.0)*M_PI;
		cerr << AR[i] << " ";
	}
	cout << endl;
	Insert_2_Sort(AR, n, por, przyp);
	for (int i = 0; i < n; i++)
	{
		cerr << AR[i] << " ";
	}
	cout << endl << por << " " << przyp << endl;
	delete[] AR;
	//out  << por << ";" << przyp << endl;

}