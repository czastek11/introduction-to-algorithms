#include "Binary_Search_Tree.h"

BST::BST()
{
	main_root = NULL;
}

Leaf* BST::GET_MROOT()
{
	return main_root;
}

void BST::SET_MROOT(Leaf * L)
{
    main_root=L;
}

void BST::INORDER(Leaf* L)
{
	if (L != NULL)
	{
		INORDER(L->left);
		std::cout << L->key<<" ";
		INORDER(L->right);
	}
}

void BST::INORDER()
{
    INORDER(main_root);
}

void BST::INREVERSEORDER(Leaf * L)
{
    if (L != NULL)
	{
		INREVERSEORDER(L->right);
		std::cout << L->key<<" ";
		INREVERSEORDER(L->left);
	}
}

void BST::INREVERSEORDER()
{
    INREVERSEORDER(main_root);
}

Leaf* BST::SEARCH(Leaf* L,std::string X)
{
	if (L == NULL ) return L;
	else if(L->key == X) return L;
	else if (X < L->key) return SEARCH(L->left, X);
	else return SEARCH(L->right, X);
}

Leaf* BST::SEARCH(std::string X)
{
   return SEARCH(main_root,X);
}

Leaf* BST::MINIMUM(Leaf* L)
{
	if (L != NULL)
	{
		while (L->left!=NULL)
		{
			L = L->left;
		}
	}
	return L;
}

Leaf * BST::MINIMUM()
{
    return MINIMUM(main_root);
}

Leaf* BST::MAXIMUM(Leaf* L)
{
	if (L != NULL)
	{
		while (L->right != NULL)
		{
			L = L->right;
		}
	}
	return L;
}

Leaf * BST::MAXIMUM()
{
    return MAXIMUM(main_root);
}

Leaf* BST::SUCCESSOR(Leaf* L)
{
	if (L != NULL)
	{
		if (L->right != NULL)
		{
			return MINIMUM(L->right);
		}
		Leaf* pom=L->root;
		while (pom != NULL && L == pom->right)
		{
			L = pom;
			pom = pom->root;
		}
		return pom;
	}
	else return L;
}

Leaf* BST::PREDECCESSOR(Leaf* L)
{
	if (L != NULL)
	{
		if (L->left != NULL)
		{
			return MAXIMUM(L->left);
		}
		Leaf* pom = L->root;
		while (pom != NULL && L == pom->left)
		{
			L = pom;
			pom = pom->root;
		}
		return pom;
	}
	else return L;
}

void BST::INSERT(Leaf* L , Leaf* Z)
{
    Z->left=NULL;
    Z->right=NULL;
    Z->root=NULL;
    Leaf* y = NULL;
    Leaf* x = L;
    while (x != NULL)
    {
        y = x;
        if (Z->key < x->key) x = x->left;
        else x = x->right;
    }
    Z->root = y;
    if (y == NULL)
    {
        L= Z;

        main_root=Z;
    }
    else if (Z->key < y->key) y->left = Z;
    else y->right = Z;
}

void  BST::INSERT(std::string k)
{
    Leaf * pom=new Leaf;
    pom->key=k;
    pom->left=NULL;
    pom->right=NULL;
    pom->root=NULL;
    INSERT(main_root,pom);
}

void BST::TRANSPLANT(Leaf* L, Leaf* u, Leaf* v)
{
	if (L!=NULL)
	{
		if (u->root == NULL) L = v;
		else if (u->root->left == u) u->root->left = v;
		else u->root->right = v;
		if (v != NULL) v->root = u->root;
	}
}

void BST::TRANSPLANT(Leaf* u, Leaf* v)
{
    TRANSPLANT(main_root,u,v);
}

void BST::DELETE(Leaf* L, std::string k)
{
	if (L != NULL)
	{
	    Leaf * z = SEARCH(L,k);
	    if(z!=NULL)
        {
            if (z->left == NULL)
            {
                TRANSPLANT(L, z, z->right);
                if(z==main_root) main_root=z->right;
            }
            else if (z->right == NULL)
            {
                TRANSPLANT(L, z, z->left);
                if(z==main_root) main_root=z->left;
            }
            else
            {
                Leaf* y = MINIMUM(z->right);
                if (y->root != z)
                {
                    TRANSPLANT(L, y, y->right);
                    y->right = z->right;
                    y->right->root = y;
                }
                TRANSPLANT(L, z, y);
                y->left = z->left;
                y->left->root = y;
                if(main_root==z) main_root=y;
            }
        }
	}
}

void BST::DELETE(std::string k)
{
    DELETE(main_root,k);
}

BST::~BST()
{
}
