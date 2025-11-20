#include<bits/stdc++.h>
using namespace std;
using LL=long long;

struct prefixTree
{
    struct node
    {
        char self = '*';
        bool end = false;
        vector<node*> children;
        node* parent = nullptr;

        node() : children(26, nullptr) {}
        node(char _self) : self(_self), children(26, nullptr) {} 
    };

    node* root;

    prefixTree()
    {
        root = new node(); 
    }

    // tworzenie slow
    void create(string &word)
    {
        // zacznij od roota
        node* curr = root;
        
        for(char letter : word)
        {
            int ind = letter - 'a';

            // jesli nie ma tej litery to ja stworz
            if(!curr->children[ind]) curr->children[ind] = new node(letter);
            
            // ustaw w dziecku ze jestes jego ojcem
            curr->children[ind]->parent = curr;
        }

        // ustaw koniec na koniec slowa
        curr->end = true;
    }

    void destructor(node* v)
    {
        // jesli jest puste to skip
        if(!v) return;

        // wchodzimy we wszystkie dzieci
        for(auto a : v->children) destructor(a);

        // usuniecie w kolejnosci od dzieci
        delete v;
    }

    ~prefixTree()
    {
        destructor(root);
    }
};
