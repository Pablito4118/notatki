#include<bits/stdc++.h>
using namespace std;
using LL=long long;

struct fenwick2d
{
    vector<vector<int>> tree;
    int n, m;

    fenwick2d(vector<vector<int>> &tab)
    {
        n = tab.size() + 1;
        m = tab[0].size() + 1;
        tree.assign(n, vector<int>(m, 0));
        
        // kopiowanie tablicy
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                tree[i][j] = tab[i - 1][j - 1];
            }
        }

        // budowanie 1 wymiaru
        for(int i = 1; i < n; i++)
        {
            int p = i + (i & -i);
            if(p < n)
            {
                for(int j = 1; j < m; j++) tree[p][j] += tree[i][j];
            }
        }

        // budowanie 2 wymiaru
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                int p = j + (j & -j);
                if(p < m) tree[i][p] += tree[i][j];
            }
        }
    }
    
    void update(int y, int x, int val)
    {
        // przechodzi po wszystkich wartosciach ktore trzymaja punkt (x, y)
        for(int i = y; i < n; i += i & -i)
        {
            for(int j = x; j < m; j += j & -j) tree[i][j] += val;
        }
    }

    int query(int y, int x)
    {
        int ans = 0;

        for(int i = y; i > 0; i -= i & -i)
        {
            for(int j = x; j > 0; j -= j & -j) ans += tree[i][j];
        }

        return ans;
    }

    int query(int y1, int x1, int y2, int x2)
    {
        // zasada wlaczen i wylaczen
        return query(y2, x2) - query(y2, x1 - 1) - query(y1 - 1, x2) + query(y1 - 1, x1 - 1);
    }
};
