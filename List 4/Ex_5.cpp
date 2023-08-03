#include <iostream>

using namespace std;

class Stack
{
public:
	Stack(int);
	bool Stack_Empty();
	void Push(double);
	double Pop();
	~Stack();

private:
	double* Stack_;
	int top;
	int size;

};

Stack::Stack(int n)
{
	if (n < 1) n = 1;
	Stack_ = new double[n];
	size = n;
	top = -1;
}

Stack::~Stack()
{
	delete[] Stack_;
}

bool Stack::Stack_Empty()
{
	if (top == -1) return 1;
	else return 0;
}

void Stack::Push(double X)
{
	if (top < size - 1)
	{
		top++;
		Stack_[top] = X;
	}
	else cout << endl << "Przepe³nienie Stosu" << endl;
}

double Stack::Pop()
{
	if (Stack_Empty())
	{
		cout << endl << "Pusty Stos" << endl;
		
	}
	else
	{
		top--;
		return Stack_[top + 1];
	}
}

int main()
{
	Stack test(10);
	//cout << test.Pop() << endl;
	for (int i = 0; i < 10; i++)
	{
		test.Push(10.0 - i);
	}
	for (int i = 0; i < 10; i++)
	{
		cout<<test.Pop()<<" ";
	}
    return 0;
}

