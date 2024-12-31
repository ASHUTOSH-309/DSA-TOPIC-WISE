#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
        Given a number n, reduce it to 1 in minimum number of operations

        Valid opertions are
        if number is even --> then division by 2 is allowed
        if number is odd then
                    increment by 1
                    decrement by 1 allowed
     */

    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    // dp[i]--> minimum steps to reduce i to 1
    // compute some initial values, by simple observation
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;

    for (int i = 5; i <= n; i++)
    {

        if (i % 2 == 0)
            dp[i] = dp[i / 2] + 1;
        else
        {
            dp[i] = min(1 + dp[i - 1], 2 + dp[(i + 1) / 2]);
            // if odd--> 1+ steps (i-1 to 1)
            // --> (i to i+1) then (i+1 to i+1/2) then (i+1/2 to 1)= 1+1+dp[i+1/2]
            // dp[i+1] is not computed but i+1<2 is for sure less than i, hence its pre-computed
        }
    }
}