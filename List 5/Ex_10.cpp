#include <iostream>
#include <fstream>
#include "Binary_Search_Tree.h"
using namespace std;

int main()
{
    BST Tree;
    fstream plik;
    plik.open("commands.txt",ios::in);
    if(plik.good())
    {
        string command,word_;
        while(plik>>command)
        {
            if(command=="QUIT") break;
            else if(command=="INSERT")
            {
            plik>>word_;
            Tree.INSERT(word_);
            }
            else if(command=="DELETE")
            {
                plik>>word_;
                Tree.DELETE(word_);
            }
            else if(command=="MINIMUM")
            {
                Leaf * pom=Tree.MINIMUM();
                if(pom!=NULL) cout<<pom->key<<endl;
                else cout<<"Empty tree"<<endl;
            }
            else if(command=="MAXIMUM")
            {
                Leaf * pom=Tree.MAXIMUM();
                if(pom!=NULL) cout<<pom->key<<endl;
                else cout<<"Empty tree"<<endl;
            }
            else if(command=="SEARCH")
            {
                plik>>word_;
                cout<<Tree.SEARCH(word_)<<endl;
            }
            else if(command=="SUCCESSOR")
            {
                plik>>word_;
                Leaf * pom=Tree.SEARCH(word_);
                if(pom!=NULL)
                {
                    pom=Tree.SUCCESSOR(pom);
                    if(pom!=NULL) cout<<pom->key<<endl;
                    else cout<<"No successor or empty tree"<<endl;
                }
                else cout<<"No instance of this name in tree"<<endl;
            }
            else if(command=="PREDECCESSOR")
            {
                plik>>word_;
                Leaf * pom=Tree.SEARCH(word_);
                if(pom!=NULL)
                {
                    pom=Tree.PREDECCESSOR(pom);
                    if(pom!=NULL) cout<<pom->key<<endl;
                    else cout<<"No predeccessor or empty tree"<<endl;
                }
                else cout<<"No instance of this name in tree"<<endl;
            }
            else if(command=="INORDER")
            {
                Tree.INORDER();
                cout<<endl;
            }
            else if(command=="INREVERSEORDER")
            {
                cout<<endl;
                Tree.INREVERSEORDER();
                cout<<endl;
            }
        }
    }
    else cout<<"error while opening file"<<endl;
}

