#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(4, 0));

    for (int i = 1; i <= n; i++)
    {
        int first, second, third;
        cin >> first >> second >> third;

        arr[i][1] = first;
        arr[i][2] = second;
        arr[i][3] = third; // arr[i][j] reward for j the activity on i th day
    }

    vector<vector<int>> dp(n+1, vector<int>(4, 0)); // dp[i][j]--> Max profit till day j when current selected item is i;
                                                      // i==1 implies its actually activity 'A' done by the boy
                                                      // i==2 implies its actually activity 'B' done by the boy
                                                      // i==3 implies its actually acitivity 'C' done by the boy on i th day
    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][2];
    dp[1][3] = arr[1][3];

    for (int i = 2; i <= n; i++){
        dp[i][1]=arr[i][1]+max(dp[i-1][2],dp[i-1][3]);
        dp[i][2]=arr[i][2]+ max(dp[i-1][1],dp[i-1][3]);
        dp[i][3]=arr[i][3]+max(dp[i-1][1],dp[i-1][2]);
    }

    cout<<max(dp[n][1],max(dp[n][2],dp[n][3]));
}