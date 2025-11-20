#include<bits/stdc++.h>
using namespace std;
using LL=long long;

int SIZE = 1e7;

vector<bool> prime(SIZE + 1, true);

void sito()
{
    prime[0] = false;
    prime[1] = false;

    for(int i = 2; i * i <= SIZE; i++)
    {
        if(prime[i])
        {
            for(int j = i * i; j <= SIZE; j += i)
            {
                prime[j] = false;
            }
        }
    }
}
