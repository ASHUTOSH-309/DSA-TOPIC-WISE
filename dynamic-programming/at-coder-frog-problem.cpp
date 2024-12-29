#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> heights(n + 1);

    for (int i = 1; i <= n; i++)
    {
        // Input n heights
        int temp;
        cin >> temp;
        heights[i] = temp;
    }

    vector<int> dp(n + 1);

    // dp[i]--> min cost required to reach form 1 to i th stone

    dp[1] = 0;
    dp[2] = abs(heights[2] - heights[1]);

    for (int i = 3; i <= n; i++)
    {

        dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]), dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }

    cout << dp[n];
}