#include<bits/stdc++.h>
using namespace std;
using LL=long long;

vector<vector<int>> graf;
vector<bool> vis;

vector<int> tour;

void eularian_tour(int v)
{
    tour.push_back(v);
    for(int u : graf[v])
    {
        if(!vis[u])
        {
            vis[u] = true;
            eularian_tour(u);
            tour.push_back(u);
        }
    }
}
