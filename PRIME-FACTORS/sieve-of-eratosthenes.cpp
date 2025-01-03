#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> sieve(ll n)
{

    vector<int> ans;
    vector<bool> prime(n + 1, true); //

    prime[0]=false;
    prime[1]=false;

    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (prime[i])
            for (int j = i * i; j <= n; j += i) prime[j] = false; // Mark all the multiples of prime factor as false
    }

    for (int i = 2; i <= n; i++)
    {
        // Iterate over the boolean array and then simply opt for the prime values
        if (prime[i])
            ans.push_back(i);
    }

    return ans;
}

int main()
{
    ll n;

    cin >> n;

    for(auto it:sieve(n)){

        cout<<it<<" ";

    }
}