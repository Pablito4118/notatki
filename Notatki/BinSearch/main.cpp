#include<bits/stdc++.h>
using namespace std;
using LL=long long;

// znajdz np 5

LL binsearch()
{
    LL L = 0, R = 1e9, ans = -1;;

    while(L <= R)
    {
        LL mid = (L + R) / 2;

        LL target = 70000000;
        
        // znajdujemy najmniejsza wartosc ktora spelnia nasze warunki
        //
        if(mid <= target)
        {
            ans = mid;
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }


    return ans;
}
