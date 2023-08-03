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

void Heapify(vector<int>& A, unsigned int i, unsigned int n)
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

void Heapsort(vector<int>& A)
{
	unsigned int n = A.size();
	for (int i = (n - 1) / 2; i >= 0; i--) Heapify(A, i, n);
	for (int i = n - 1; i >= 1; i--)
	{
		swap(A.at(i), A.at(0));
		n--;
		Heapify(A, 0, n);
	}
}

void Heapify(vector<int>& A, unsigned int i, unsigned int n, unsigned int& por, unsigned int& przyp, unsigned int& pam,unsigned int sumpam)
{
	unsigned int sumpam2 = sumpam;
	unsigned int l = 2 * i + 1, r = 2 * i + 2, w = i;
	sumpam2 += sizeof(unsigned int) * 3;
	por++;
	if (l<n && A.at(l)>A.at(w)) w = l;
	por++;
	if (r<n && A.at(r)>A.at(w)) w = r;
	if (w != i)
	{
		swap(A.at(i), A.at(w));
		przyp += 3;
		Heapify(A, w, n, por, przyp, pam,sumpam2);
	}
	if (sumpam2 > pam) pam = sumpam2;
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

void HeapInsert(vector<int>& A, unsigned int i)
{
	if (i != 0)
	{
		unsigned int parent = (i - 1) / 2;
		if (A.at(parent) < A.at(i))
		{
			swap(A.at(parent), A.at(i));
			HeapInsert(A, parent);
		}
	}
}

void HeapInsert(vector<int>& A, unsigned int i, unsigned int& por, unsigned int& przyp, unsigned int& pam, unsigned int sumpam)
{
	unsigned int sumpam2 = sumpam;
	if (i != 0)
	{
		unsigned int parent = (i - 1) / 2;
		sumpam2 += sizeof(unsigned int);
		por++;
		if (A.at(parent) < A.at(i))
		{
			swap(A.at(parent), A.at(i));
			przyp += 3;
			HeapInsert(A, parent,por,przyp,pam,sumpam2);
		}
	}
	if (sumpam2 > pam) pam = sumpam2;
}

void HeapInsertion_Sort(vector<int>& A)
{
	
	for (unsigned int n = A.size(); n >= 2; n--)
	{
		for (unsigned int j = 1; j < n; j++) HeapInsert(A, j);
		swap(A.at(n-1), A.at(0));
	}
}

void HeapInsertion_Sort(vector<int>& A, unsigned int& por, unsigned int& przyp, unsigned int& pam)
{
	pam = 0;
	unsigned int sumpam = 0;
	for (unsigned int n = A.size(); n >= 2; n--)
	{
		for (unsigned int j = 1; j < n; j++) HeapInsert(A, j,por,przyp,pam,sumpam);
		swap(A.at(n - 1), A.at(0));
		przyp += 3;
	}
	if (sumpam > pam) pam = sumpam;
}

int main()
{
	fstream plik1, plik2;
	vector<int> kloc, klocuch;
	vector<unsigned int> array_size,por_1,przyp_1,pam_1, por_2, przyp_2, pam_2;
	srand(time(NULL));
	int  pom;
	unsigned int por1 = 0, przyp1 = 0, pam1 = 0, por2 = 0, przyp2 = 0, pam2 = 0;
	for (int j = 10; j < 2500; j++)
	{
		kloc.clear();
		klocuch.clear();
		por1 = 0, przyp1 = 0, pam1 = 0, por2 = 0, przyp2 = 0, pam2 = 0;
		//n = rand() % 60 + 1;
		for (int k = 0; k < j; k++)
		{
			pom = rand() % 250;
			kloc.push_back(pom);
			klocuch.push_back(pom);
		}
		Heapsort(kloc, por1, przyp1, pam1);
		HeapInsertion_Sort(klocuch, por2, przyp2, pam2);
		if (!check_sort(kloc))
		{
			cout << "zly case " << j << endl;
			for (int k = 0; k < j; k++) cout << kloc.at(k) << " ";
			break;
		}
		if (!check_sort(klocuch))
		{
			cout << "zly case " << j << endl;
			for (int k = 0; k < j; k++) cout << klocuch.at(k) << " ";
			break;
		}
		array_size.push_back(j); por_1.push_back(por1); przyp_1.push_back(przyp1); pam_1.push_back(pam1); por_2.push_back(por2); przyp_2.push_back(przyp2); pam_2.push_back(pam2);
	}
	//for (int k = 0; k < n; k++) cout << klocuch.at(k) << " ";
	plik1.open("HP_9.data", ios::out);
	for (int i = 0; i < array_size.size(); i++)
	{
		plik1 << array_size.at(i) << " " << por_1.at(i) << " " << przyp_1.at(i) << " " << pam_1.at(i) << endl;
	}
	plik1.close();
	plik2.open("HPIN_9.data", ios::out);
	for (int i = 0; i < array_size.size(); i++)
	{
		plik2 << array_size.at(i) << " " << por_2.at(i) << " " << przyp_2.at(i) << " " << pam_2.at(i) << endl;
	}
	plik2.close();
	return 0;
}