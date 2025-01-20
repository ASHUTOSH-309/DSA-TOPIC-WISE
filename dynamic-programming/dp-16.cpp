#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{

    int n;
    cin >> n;

    int i = 1;
    vector<int> A(n + 1, 0);// A[i]--> Profit gained by doing easy work on the i th day
    vector<int> B(n + 1, 0);// B[i]--> Profit gained by doing hard work on the i th day

    while (i <= n)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        A[i] = temp1;
        B[i] = temp2;
    }

    //we are given two arrays
    /* 
        at each day we can
         - perform Easy task or hard task
         - also hard task can only be opted on i th day if on i-1 th day we are having holiday or no task is performed
        
        this gives rise to 3 states 
        --> on i th day we can
          ---> Do the easy task 
          ---> Do the Hard task
          ---> Can choose to rest

        Now we have to do maximize the profit by selecting the task to do on i th day , in this manner we have to maximize the profit  
    
     */

    vector<vector<int>> dp(n+1,vector<int>(3,0));
    // dp[i][j] --> Max profit if on ith day we have like jth nature job to be selected then the max profit


    dp[1][0]=A[1];// 0--> Easy 1---> Hard 2----> Rest Day Man
    dp[1][1]=B[1];
    dp[1][2]=0;


    for(int i=2;i<=n;i++){
        dp[i][0]=A[i]+max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        dp[i][1]=B[i]+dp[i-1][2];// Hard Task Krega to i-1 th day par zero Earning hoga 
        dp[i][2]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
    }

    cout<<max({dp[n][0],dp[n][1],dp[n][2]});

}