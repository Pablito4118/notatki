#include<bits/stdc++.h>
using namespace std;
using LL=long long;

struct DSU
{
    vector<int> parent, size;
    
    DSU(int n)
    {
        parent.resize(n + 1);
        size.assign(n + 1, 1);

        // generowanie zbioru
        for(int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int a)
    {
        // jesli jestes reprezentatnem to super
        if(parent[a] = a) return a;

        // przyspieszenie nastepnych find 
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        // jesli sa w tym samym zbiorze to nic nie rob
        if(a == b) return; 

        // optymalizacja by nie robic za duzo operacji
        if(size[a] < size[b]) swap(a, b);

        // polaczenie 2 zbiorow
        parent[b] = a;
        
        // wielkosc zbioru
        size[a] += size[b];
    }
};
