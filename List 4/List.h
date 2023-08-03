#pragma once

struct Pole
{
	Pole* next;
	Pole* prev;
	double key;
};

class Lista
{
public:
	Lista();
	bool Empty();
	unsigned int Size();
	Pole* Search(double);
	Pole* Point(int);
	void Add(double);
	void Delete(Pole*);
	void pop(int);
	double operator [](int);
	double Show_Key(Pole*);
	void Insert(int,double);
	void Merge_with( Lista&);
	void Merge_with_insert(Lista&,int);
	void Clear_List();
	void Swap(Pole*, Pole*);
	void Insertion_Sort();
	~Lista();

private:
	Pole* head;
	Pole* tail;
};

