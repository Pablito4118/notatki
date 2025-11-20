#include<bits/stdc++.h>
using namespace std;
using LL=long long;

LL MOD = 1e9 + 7;

LL pot(LL a, LL wykladnik)
{
    // zakonczenie rekurenci, znak uniwersalny zbioru
    if(wykladnik == 0) return 1 % MOD;
    
    // jesli jest podzielne przez 2 to zwroc normlane
    if(wykladnik % 2 == 0) return (pot(a, wykladnik / 2) * pot(a, wykladnik / 2)) % MOD;

    // jesli nie to normalna iteracja ale wymnozona przez a
    return (((a * pot(a, wykladnik / 2)) % MOD) * pot(a, wykladnik / 2)) % MOD;
}
