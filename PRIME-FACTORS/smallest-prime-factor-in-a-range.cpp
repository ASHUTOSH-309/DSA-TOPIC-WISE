#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MAXN = 1000000;
vector<ll> spf(MAXN + 1);

void computeSpf()
{

    // compute the spf for all the numbers in the range 1 to 10 power 6
    for (ll i = 2; i <= MAXN; i++)
        spf[i] = i;
    // sieve of erathosnes

    for (ll i = 2; i < sqrt(MAXN); i++)
    {
        if (spf[i] == i)
        {
            // it implies that i is actually a prime number, now prime detected simply start marking its
            // multiples as non primes
            for (ll j = i * i; j <= MAXN; j += i)
            {
                if (spf[j] == j)
                {
                    // j is for sure a multiple of i, and i is a prime number as already checked before entering intio the loop
                    // simply update the spf of j to i, as it's a better alternative
                    spf[j] = i;
                }
            }
        }
    }
}

int main()
{

    computeSpf();
    for (ll i = 2; i <= 20; i++)
    {
        cout << spf[i] << " ";
    }
}