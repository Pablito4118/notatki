#include<bits/stdc++.h>
using namespace std;
using LL=long long;

int n = 20;
vector<bool> vis(n, false);
void DFS(vector<vector<int>> &graf, int v)
{
    for(int a : graf[v])
    {
        if(!vis[a])
        {
            vis[a] = true;
            DFS(graf, a);
        }
    }
}
