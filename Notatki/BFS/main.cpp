#include<bits/stdc++.h>
using namespace std;
using LL=long long;

int BFS(vector<vector<int>> &graf, int start, int end, int size)
{
    queue<int> kolejka;
    vector<bool> vis(n, false);
    vector<int> dist(n, 0);
    
    vis[start] = true;
    kolejka.push(start);
    dist[start] = 0;
    while(!kolejka.empty())
    {
        int v = kolejka.front();
        kolejka.pop();

        for(int a : graf[v])
        {
            if(!vis[a])
            {
                vis[a] = true;
                kolejka.push(a);
                dist[a] = dist[v] + 1;
            }
        }
    }
    return dist[end];
}
