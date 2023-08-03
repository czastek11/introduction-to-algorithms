#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	Lista Hum;
	for (int i = 0; i < 15; i++)
	{
		Hum.Add(15 - i);
	}
	//Hum.Swap(Hum.Point(0), Hum.Point(1));
	Hum.Insertion_Sort();
	for (int i = 0; i < Hum.Size(); i++) cout << Hum[i] << " ";
	return 0;
}
