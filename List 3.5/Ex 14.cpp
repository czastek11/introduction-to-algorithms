#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>

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

unsigned int PARTITION(vector<int>& A,  int p,  int k)
{
    int x = A.at(k);
    int i = p - 1;
    for (unsigned int j = p; j < k; j++)
    {
        if (A.at(j) < x)
        {
            i++;
            swap(A.at(i), A.at(j));
        }
    }
    swap(A.at(i + 1), A.at(k));
    return i+1;
}

void QUICKSORT(vector<int>& A, int p,  int k)
{
     int s;
    if (p < k)
    {
        s = PARTITION(A, p, k);
        QUICKSORT(A, p, s - 1);
        QUICKSORT(A, s + 1, k);
    }
}

int main()
{
	vector<int> kloc;
	srand(time(NULL));
	int n, pom;
	for (int j = 0; j < 1000; j++)
	{
		kloc.clear();
		n = rand() % 20 + 1;
		for (int k = 0; k <n ; k++)
		{
			kloc.push_back(rand() % 41);
		}
		QUICKSORT(kloc,0,kloc.size()-1);
		if (!check_sort(kloc))
		{
			cout << "zly case " << j << endl;
			for (int k = 0; k < n; k++) cout << kloc.at(k) << " ";
			break;
		}
	}
}
