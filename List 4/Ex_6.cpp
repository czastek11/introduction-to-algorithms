#include <iostream>

using namespace std;

class Quene
{
public:
	Quene(int);
	void Enquene(double);
	double Dequene();
	~Quene();

private:
	double* Quene_;
	int size;
	int head;
	int tail;
};

Quene::Quene(int n)
{
	if (n < 1) n = 1;
	Quene_ = new double[n];
	size = n;
	head = -1;
	tail = 0;
}

void Quene::Enquene(double X)
{
	if (head == -1)
	{
		head = 0;
		tail = 1;
		Quene_[head] = X;
	}
	else if (tail==size)
	{
		tail = 0;
		if (tail == head)
		{
			tail = size;
			cout << endl << "Pelna kolejka" << endl;
		}
		else
		{
			Quene_[tail] = X;
			tail++;
		}
	}
	else if (tail == head) cout << endl << "Pelna kolejka" << endl;
	else
	{
		Quene_[tail] = X;
		tail++;
	}
}

double Quene::Dequene()
{
	if (head == -1)
	{
		cout << endl << "Pusta kolejka" << endl;
	}
	else if (head == tail-1)
	{
		int pom = head;
		head = -1;
		tail = 0;
		return Quene_[pom];
	}
	else if (head == size - 1)
	{
		head = 0;
		return Quene_[size - 1];
	}
	else
	{
		int pom = head;
		head++;
		return Quene_[pom];
	}
}

Quene::~Quene()
{
	delete[] Quene_;
}

int main()
{
	Quene test(10);
	//cout << test.Pop() << endl;
	for (int i = 0; i < 10; i++)
	{
		test.Enquene(10.0 - i);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << test.Dequene() << " ";
	}
	return 0;
}

