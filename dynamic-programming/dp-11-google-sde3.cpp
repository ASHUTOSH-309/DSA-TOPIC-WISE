#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main()
{
    // Reduce a given n to 1;
    /*
    Allowed operations
    --> reduce by 1---> cost a
    --> divide by 3---> cost x
    --> divide by 5---> cost y
    --> divide by 7---> cost z

     */

    int n;
    cin >> n;

    int a, x, y, z;
    cin >> a >> x>> y>> z;

    vector<int> dp(n + 1, 0); // dp[i]--> tells the minimum cost to reduce i to 1 by doing the aforementioned
    // operations in the best possible manner

    dp[1] = 0; // cost for 1-->1 obviously -->0

    for (int i = 2; i <= n; i++)
    {

        dp[i] = min(
            min(dp[i - 1] + a,(i % 3 == 0) ? (dp[i / 3] + x) : INT_MAX),
            min((i % 5 == 0) ? (dp[i / 5] + y) : INT_MAX,(i % 7 == 0) ? dp[i / 7] + z : INT_MAX)
        );
    }


    cout<<dp[n];
}