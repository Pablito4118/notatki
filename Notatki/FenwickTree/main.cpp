#include<bits/stdc++.h>
using namespace std;
using LL=long long;

struct fenwick
{
    vector<int> tree;
    int n;

    fenwick(vector<int> &tab)
    {
        n = tab.size() + 1;
        tree.assign(n, 0);
        
        // skopiuj zainicjowany vector
        copy(tab.begin(), tab.end(), tree.begin() + 1);
        
        for(int i = 1; i < n; i++)
        {
            // znajdz ojca
            int p = i + (i & -i);

            // dodaj do ojca dziecko
            if(p < n) tree[p] += tree[i];
        }
    }
    
    void update(int ind, int val)
    {
        // przejdz sie po drzewie
        for(; ind < n; ind += ind & -ind) tree[ind] += val;
    }

    int query(int ind)
    {
        int ans = 0;

        // od konca sie przejdz po drzewie
        for(; ind > 0; ind -= ind & -ind) ans += tree[ind];

        return ans;
    }

    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};
