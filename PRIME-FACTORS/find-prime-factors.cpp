#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

unordered_map<ll, ll> primeFactors(ll n)
{

    unordered_map<long long, long long> prime_factors;

    // we have to return all the prime factors of n along with their frequencies

    while (n % 2 == 0)
    {
        n = n / 2;
        prime_factors[2]++;
    }

    for (ll i = 3; i <= sqrt(n); i+=2)
    {

        while (n % i == 0)
        {
            prime_factors[i]++;
            n = n / i;
        }
    }

    if(n>2) prime_factors[n]++;

    return prime_factors;
}

int main()
{

    ll n;
    cin >> n;

    for (auto it : primeFactors(n))
    {

        // iterate over the returnred unordered map

        cout << "prime factor:" << it.first << " freq:" << it.second << endl;
    }

    return 0;
}