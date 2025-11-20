#include<bits/stdc++.h>
using namespace std;
using LL=long long;

struct segmentTree
{
    struct node
    {
        int l, r, mx;
        
        node() : l(-1), r(-1), mx(INT_MIN) {}
        node(int _l, int _r, int _mx) : l(_l), r(_r), mx(_mx) {}
    };

    int base = 1;
    vector<node> tree;
    vector<int> lazy;

    segmentTree(vector<int> &tab)
    {
        while(base < int(tab.size())) base *= 2;

        tree.assign(2 * base, node());
        lazy.assign(2 * base, 0);
        
        // dodawanie elementow do dzieci
        for(int i = 0; i < int(tab.size()); i++) tree[base + i] = node(i, i, tab[i]);
        
        // zapelnienie wolnych dzieci
        for(int i = int(tab.size()); i < base; i++) tree[base + i] = node(i, i, INT_MIN);
        
        // generowanie rodzicow
        for(int i = base; i > 0; i--) tree[i] = node(tree[2 * i].l, tree[2 * i + 1].r, max(tree[2 * i].mx, tree[2 * i + 1].mx));
    }
        
    void check(int v)
    {
        // sprawdz czy trzeba zaktualizowac
        if(lazy[v] != 0)
        {
            tree[v].mx += lazy[v];
            
            // sprawdz czy jestes lisciem
            if(v < base)
            {
                lazy[2 * v] += lazy[v];
                lazy[2 * v + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void update(int v, int l, int r, int val)
    {
        // zaktualizuj
        check(v);

        // brak pokrycia zatrzymaj sie
        if(tree[v].l > r || tree[v].r < l) return;

        // calkowite pokrycie wiec nie idziemy glebiej
        if(tree[v].l >= l && tree[v].r <= r)
        {
            tree[v].mx += val;
            if(v < base)
            {
                lazy[2 * v] += val;
                lazy[2 * v + 1] += val;
            }
            return;
        }
        
        // czesciowe pokrycie wiec idziemy do dzieci
        update(2 * v, l, r, val);
        update(2 * v + 1, l, r, val);

        // wracajac od dzieci sprawdzamy swoja aktualnosc
        tree[v].mx = max(tree[2 * v].mx, tree[2 * v + 1].mx);
    }

    int read(int v, int l, int r)
    {
        // sprawdz czy jestesmy na biezaco
        check(v);

        // jesli calkowicie pokrywa to zwraca maxa
        if(tree[v].l >= l && tree[v].r <= r) return tree[v].mx;

        // brak pokrycia wiec nic nie zwraca
        if(tree[v].l < l || tree[v].r > r) return INT_MIN;

        // czesciowe pokrycie = zejdz do dzieci
        return max(read(2 * v, l, r), read(2 * v + 1, l, r));
    }
};
