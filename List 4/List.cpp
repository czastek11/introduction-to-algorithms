#include "List.h"

Lista::Lista()
{
	head = nullptr;
	tail = nullptr;
}

bool Lista::Empty()
{
	if (head == nullptr)
	{
		return true;
	}
	else return false;
}

unsigned int Lista::Size()
{
	if (head == nullptr) return 0;
	else
	{
		unsigned int n=1;
		Pole* palec=head;
		while (palec->next != nullptr)
		{
			palec = palec->next;
			n++;
		}
		return n;
	}
}

Pole* Lista::Search(double X)
{
	if (head != nullptr)
	{
		Pole* palec = head;
		if (head->key == X) return head;
		while (palec->next != nullptr)
		{
			palec = palec->next;
			if (palec->key == X) return palec;
		}
		return nullptr;
	}
	return nullptr;
	
}

Pole* Lista::Point(int i)
{
	if (head != nullptr)
	{
		bool range = true;
		Pole* palec = head;
		for (int j = 0; j < i; j++)
		{
			if (palec->next != nullptr)
			{
				palec = palec->next;
			}
			else
			{
				range = false;
				break;
			}
		}
		if (range)
		{
			return palec;
		}
	}
}

void Lista::Add(double X)
{	Pole* palec = head;
	if (head==nullptr)
	{
		head = new Pole;
		head->prev = nullptr;
		head->next = nullptr;
		head->key = X;
		tail = head;
	}
	else
	{
		while (palec->next != nullptr)
		{
			palec = palec->next;
		}
		palec->next = new Pole;
		palec->next->next = nullptr;
		palec->next->prev = palec;
		palec->next->key = X;
		tail=palec->next;
	}
	
}

void Lista::Delete(Pole* Y)
{
	if (Y != nullptr)
	{
		if (Y->next == nullptr && Y->prev == nullptr)
		{
			head = nullptr;
			tail = nullptr;
			delete Y;
		}
		else if (Y->next == nullptr && Y->prev != nullptr)
		{
			Y->prev->next = nullptr;
			tail = Y->prev;
			delete Y;
		}
		else if (Y->next != nullptr && Y->prev == nullptr)
		{
			Y->next->prev = nullptr;
			head = Y->next;
			delete Y;
		}
		else
		{
			Y->prev->next = Y->next;
			Y->next->prev = Y->prev;
			delete Y;
		}
	}
	//Lista* pom;
	
}

void Lista::pop(int i)
{
	if (head != nullptr)
	{
		bool range = true;
		Pole* palec = head;
		for (int j = 0; j < i; j++)
		{
			if (palec->next != nullptr)
			{
				palec = palec->next;
			}
			else
			{
				range = false;
				break;
			}
		}
		if (range)
		{
			Delete(palec);
		}
	}
}

double Lista::operator[](int i)
{
	if (head != nullptr)
	{
		bool range=true;
		Pole* palec=head;
		for (int j = 0; j < i; j++)
		{
			if (palec->next != nullptr)
			{
				palec = palec->next;
			}
			else
			{
				range = false;
				break;
			}
		}
		if (range) return palec->key;
	}

	return 0;
}

double Lista::Show_Key(Pole* Y)
{
	if (Y != nullptr) return Y->key;
}

void Lista::Insert(int i, double X)
{
	if (head != nullptr)
	{
		bool range = true;
		Pole* palec = head;
		for (int j = 0; j < i; j++)
		{
			if (palec->next != nullptr)
			{
				palec = palec->next;
			}
			else
			{
				range = false;
				break;
			}
		}
		if (range)
		{
			if (palec->prev != nullptr)
			{
				Pole* pom = palec->prev;
				palec->prev = nullptr;
				palec->prev = new Pole;
				palec->prev->prev = pom;
				palec->prev->prev->next = palec->prev;
				palec->prev->next = palec;
				palec->prev->key = X;
			}
			else
			{
				palec->prev = new Pole;
				palec->prev->prev = nullptr;
				palec->prev->next = palec;
				palec->prev->key = X;
				head = palec->prev;

			}
			
		}
	}
}

void Lista::Merge_with( Lista& B)
{
	if (head != nullptr && B.head != nullptr)
	{
		Pole* pom= tail;
		tail->next = B.head;
		tail = B.tail;
		B.head->prev = pom;
		B.head = head;
		B.head = nullptr;
		B.tail = nullptr;
	}
	else if (B.head != nullptr)
	{
		head = B.head;
		tail = B.tail;
		B.head = nullptr;
		B.tail = nullptr;
	}
}

void Lista::Merge_with_insert(Lista& B,int i)
{
	if (head != nullptr)
	{
		bool range = true;
		Pole* palec = head;
		for (int j = 0; j < i; j++)
		{
			if (palec->next != nullptr)
			{
				palec = palec->next;
			}
			else
			{
				range = false;
				break;
			}
		}
		if (range)
		{
			if (palec->prev != nullptr)
			{
				Pole* pom = palec->prev;
				palec->prev = B.tail;
				B.tail->next = palec;
				B.tail = tail;
				B.head->prev = pom;
				pom->next = B.head;
				B.head = head;
				B.head = nullptr;
				B.tail = nullptr;
			}
			else
			{
				head = B.head;
				B.tail->next = palec;
				palec->prev = B.tail;
				B.tail = tail;
				B.head = nullptr;
				B.tail = nullptr;
			}
			
		}
	}
}

void Lista::Clear_List()
{
	if (head != nullptr)
	{
		Pole* palec = head;
		while (palec->next != nullptr)
		{
			palec = palec->next;
			delete palec->prev;
		}
		delete palec;
		head = nullptr;
		tail = nullptr;
	}
}

void Lista::Swap(Pole* A, Pole* B)
{
	if (A->next = B)
	{
		if (A->prev == nullptr && B->next == nullptr)
		{
			A->prev = B;
			A->next = nullptr;
			B->next = A;
			B->prev = nullptr;
			head = B;
			tail = A;
		}
		else if (A->prev != nullptr && B->next == nullptr)
		{
			B->next = A;
			B->prev = A->prev;
			B->prev->next = B;
			A->prev = B;
			A->next = nullptr;
			tail = A;
		}
		else if (A->prev == nullptr && B->next != nullptr)
		{
			A->prev = B;
			A->next = B->next;
			A->next->prev = A;
			B->next = A;
			B->prev = nullptr;
			head = B;
		}
		else
		{
			Pole* pom = A->prev;
			A->prev = B;
			A->next = B->next;
			A->next->prev = A;
			B->next = A;
			B->prev = pom;
			B->prev->next = B;
		}
	}
	
}

void Lista::Insertion_Sort()
{
	int j;
	double x;
	Pole* pom1;
	for (int i = 1; i < Size(); i++)
	{
		x = (*this)[i];
		j = i - 1;
		while (j >= 0)
		{
			if ((*this)[j] > x)
			{
				pom1=Point(j + 1);
				Swap(pom1->prev, pom1);
				j--;
			}
			else break;
		}
		Point(j + 1)->key = x;
	}
}

Lista::~Lista()
{
	this->Clear_List();
}
