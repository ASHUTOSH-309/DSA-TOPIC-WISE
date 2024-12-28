#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n; // Input the number of cities
    vector<int> cost(n + 1);
    for (int i = 1; i <= n; i++) cin >> cost[i];

    // Allowed steps are jump of 1 or 3
    // with a cost incurred for city i to j as abs(cost[j]-cost[i])
    vector<int> dp(n + 1);
    // dp[i]--> min cost in order to reach the city i starting from the first city
    //  find solutions for the base cases

    dp[1] = 0;
    dp[2] = abs(cost[2] - cost[1]);
    dp[3] = dp[2] + abs(cost[2] - cost[3]);

    for (int i = 4; i <= n; i++)
    {
        int costFor1StepJump = abs(cost[i] - cost[i - 1]);
        int costFor3StepJump = abs(cost[i] - cost[i - 3]);
        dp[i] = min(dp[i - 1] + costFor1StepJump, dp[i - 3] + costFor3StepJump);
    }

    cout<<dp[n];// Output the min cost  for travel from city 1 to n

}