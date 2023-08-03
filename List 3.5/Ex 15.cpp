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

unsigned int PARTITION_R(vector<int>& A, int p, int k)
{
    int pom = rand() % (k-p+1)+p;
    int x = A.at(pom);
    int i = p - 1;
    int hop = 1;
    for (unsigned int j = p; j <= k; j++)
    {
        if (A.at(j) < x)
        {
            i++;
            if (i == pom)
            {
                i++;
                hop--;
            }
            swap(A.at(i), A.at(j));
        }
    }
    swap(A.at(i + hop), A.at(pom));
    return i + hop;
}

void Randomized_QUICKSORT(vector<int>& A, int p, int k)
{
    int s;
    if (p < k)
    {
        s = PARTITION_R(A, p, k);
        Randomized_QUICKSORT(A, p, s - 1);
        Randomized_QUICKSORT(A, s + 1, k);
    }
}

int main()
{
    vector<int> kloc,kloc_pom;
    srand(time(NULL));
    int n, pom;
    for (int j = 0; j < 1000; j++)
    {
        kloc.clear();
        kloc_pom.clear();
        n = rand() % 20 + 1;
        for (int k = 0; k < n; k++)
        {
            pom = rand() % 41;
            kloc.push_back(pom);
            kloc_pom.push_back(pom);
        }
        Randomized_QUICKSORT(kloc, 0, kloc.size() - 1);
        if (!check_sort(kloc))
        {
            cout << "zly case " << j << endl;
            for (int k = 0; k < n; k++) cout << kloc.at(k) << " ";
            cout << endl;
            for (int k = 0; k < n; k++) cout << kloc_pom.at(k) << " ";
            cout << endl;
            break;
        }
    }
}
