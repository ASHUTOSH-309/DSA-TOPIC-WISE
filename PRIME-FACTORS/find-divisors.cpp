#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    set<int> divisors; // To store all divisors of n

    for (int i = 1; i <= n - 1; i++)
    {

        if (n % i == 0)
        {
            if (n / i != i)
            {
                divisors.insert(i);
                divisors.insert(n / i);
            }
            else{
                // when n/i = i then both the forward and backward factor would be the same
                divisors.insert(i);
            }
        }
    }


    for(auto it:divisors) cout<<it<<endl;
}