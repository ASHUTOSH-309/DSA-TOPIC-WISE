#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[100000][5][5];

int main()
{

    int n;
    cin >> n;

    vector<ll> b(n + 1, 0);
    vector<ll> d(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        cin >> d[i];
    }

    // Now at each index we can select either
    // from array b or d , and the task is to maximize the sum
    // also there should not be three or more consecutive selections form the same array (b or d)

    // Now we are requried to create dp array which must have some way to track what were the selections at
    // two indices, then only it is possible to determine the max sum from the array

    // dp[i][j][k]--> implies (1<=j,k<=2) 1--> corresponds to the fact that selection is done from array b, and 2--> d
    // at i th index --> jth array guy is selected
    // at i-1 th index --> k th array guy is selected

    dp[1][1][1] = b[1];
    dp[1][1][2] = b[1];
    dp[1][2][1] = d[1];
    dp[1][2][2] = d[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i][1][1] = b[i] + b[i - 1] + max(dp[i - 2][2][1], dp[i - 2][2][2]);
        dp[i][2][2] = d[i] + d[i - 1] + max(dp[i - 2][1][2], dp[i - 2][1][1]);
        dp[i][1][2] = b[i] + d[i - 1] + max({dp[i - 2][2][1], dp[i - 2][1][2], dp[i - 2][1][1]});
        dp[i][2][1] = d[i] + b[i - 1] + max({dp[i - 2][1][1], dp[i - 2][1][2], dp[i - 2][2][2], dp[i - 2][2][1]});
    }

    cout<< max({dp[n][1][1], dp[n][1][2], dp[n][2][1], dp[n][2][2]});
}
