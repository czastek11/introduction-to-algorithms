#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	Lista A;
	for (int i= 0; i < 10; i++) A.Add(i * 1.5);
	cout << A.Size() << endl;
	for (int i = 0; i < 10; i++) cout << A[i] << endl;
	Lista B;
	cout << endl;
	for (int i = 0; i < 10; i++) B.Add(i * -2.1);
	for (int i = 0; i < 10; i++) cout << B[i] << endl;
	A.Merge_with(B);
	cout << endl;
	for (int i = 0; i < A.Size(); i++) cout << A[i] << endl;
	A.pop(12);
	for (int i = 0; i < A.Size(); i++) cout << A[i] << endl;
	return 0;
}
