#pragma once
#include <iostream>
#include <string>
struct Leaf
{
	Leaf* root;
	Leaf* left;
	Leaf* right;
	std::string key;
};

class BST
{
public:
	BST();
	Leaf* GET_MROOT();
	void SET_MROOT(Leaf *);
	void INORDER(Leaf*);
	void INORDER();
	void INREVERSEORDER(Leaf*);
	void INREVERSEORDER();
	Leaf* SEARCH(Leaf*, std::string);
	Leaf* SEARCH(std::string);
	Leaf* MINIMUM(Leaf*);
	Leaf* MINIMUM();
	Leaf* MAXIMUM(Leaf*);
	Leaf* MAXIMUM();
	Leaf* SUCCESSOR(Leaf*);
	Leaf* PREDECCESSOR(Leaf*);
	void INSERT(Leaf*,Leaf*);
	void INSERT(std::string);
	void TRANSPLANT(Leaf*, Leaf*, Leaf*);
	void TRANSPLANT(Leaf*, Leaf*);
	void DELETE(Leaf*, std::string);
	void DELETE(std::string);
	~BST();

private:
	Leaf* main_root;
};

