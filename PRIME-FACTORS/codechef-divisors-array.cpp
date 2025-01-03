#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

const ll MAXI = 1000000;
const ll MOD = 1e9 + 7;
vector<int> spf(MAXI + 1, 0);

void computeSpf()
{
    for (ll i = 1; i <= MAXI; i++)
        spf[i] = i;
    // just simple modification in sieve of eartosthenes

    for (ll i = 2; i * i <= MAXI; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= MAXI; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    // computation for spf done
}

// the below function will generate the map of prime factors using spf in atmax 20 steps
unordered_map<ll, ll> PrimeFactorsUsingSpf(ll val)
{

    unordered_map<ll, ll> mpp;
    while (val != 1)
    {
        ll d = spf[val];
        mpp[d]++;
        val = val / d;
    }

    return mpp;
}

int main()
{
    // your code goes here
    computeSpf();
    ll N, M;
    cin >> N >> M;
    unordered_map<ll, ll> mapForFactorial;

    for (int i = 2; i <= M; i++)
    {
        unordered_map<ll, ll> mpp = PrimeFactorsUsingSpf(i);
        for (auto it : mpp)
        {
            mapForFactorial[it.first] += it.second;
        }
    }

    //  vector < ll > arr(N + 1);
    vector<ll> b(N + 1);
    for (ll i = 1; i <= N; i++)
    {
        cin >> b[i];
    }

    // our a and b array are ready
    for (ll i = 1; i <= N; i++)
    {
        unordered_map<ll, ll> PrimeFactorsForCurrentValue = PrimeFactorsUsingSpf(b[i]);

        // prime factors after multiplication with M factorial
        for (auto it : mapForFactorial)
        {
            PrimeFactorsForCurrentValue[it.first] += it.second;
        }

        // Now simply iterate over the map, increment each prime factor frequency by 1 and then perfom
        // the multiplication that will give you the number of divisors of 6,12,18
        ll ans = 1;
        for (auto it : PrimeFactorsForCurrentValue)
        {
            ans = ans * (it.second + 1);
        }
        ans = ans % MOD;
        cout << ans << " ";
    }
}