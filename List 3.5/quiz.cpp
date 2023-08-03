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

void PARTITION_R_DUAL(vector<int>& A, int p, int k,int& s1,int& s2)
{
    int pom1 = rand() % (k - p + 1) + p;
    int pom2 = rand() % (k - p + 1) + p;
    if (pom2 < pom1) swap(pom1, pom2);
    int p1 = A.at(pom1);
    int p2 = A.at(pom2);
    if (A.at(pom2) < A.at(pom1))
    {
        swap(A.at(pom2), A.at(pom1));
    }
    int i1 = p - 1;
    int i2 = k + 1;
    int hop1 = 1;
    bool hop2=0,hop3=0;
    int j = p;
    while (j <= k)
    {
        if (j == i2) break;
        if (A.at(j) < p1)
        {
            i1++;
            if (i1 == pom1) 
            { 
                i1++;
                hop1--;
            }
            swap(A.at(i1), A.at(j));
            j++;
        }
        else if (A.at(j) > p2)
        {
            i2--;
            if (i2 == pom2)
            {
                i2--;
                hop2=true;
            }
            swap(A.at(i2), A.at(j));
        }
        else j++;
    }
    swap(A.at(i1 + hop1), A.at(pom1));
    s1 = i1 + hop1;
    s2 = pom2;
    if (hop2)
    {
        swap(A.at(i2), A.at(pom2));
        s2 = i2;
    }
}

void Randomized_QUICKSORT_DUAL(vector<int>& A, int p, int k)
{
    int s1,s2;
    if (p < k)
    {
        PARTITION_R_DUAL(A, p, k,s1,s2);
        Randomized_QUICKSORT_DUAL(A, p,s1);
        Randomized_QUICKSORT_DUAL(A, s1+1, s2);
        Randomized_QUICKSORT_DUAL(A, s2+1, k);
    }
}

int main()
{
    vector<int> kloc;// kloc_pom;
    srand(time(NULL));
    int n, pom;
    for (int k = 0; k <20; k++)
    {
        pom = rand() % 41;
        kloc.push_back(pom);
    }
    for (int k = 0; k < 20; k++) cout << kloc.at(k) << " ";
    cout << endl;
    int s1, s2;
    PARTITION_R_DUAL(kloc, 0, 19, s1, s2);
    cout << s1 << " " << s2 << endl;
    //Randomized_QUICKSORT_DUAL(kloc, 0, kloc.size() - 1);
    for (int k = 0; k < 20; k++) cout << kloc.at(k) << " ";
    cout << endl;

    /*
    
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
    */
    return 0;
}