#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cout<<"Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n+1);

    for (int i = 1; i <= n; i++){
        cin>>arr[i];
    }

// Now already has been read;
    vector<int> dp(n + 1);

// There can be a case where all elements can be negative in that case
// we will opt for a null set
    dp[1]=max(0,arr[1]);
    dp[2]=max(arr[1],arr[2]);
    dp[3]=max(arr[3]+dp[1],dp[2]);

    // Now incrementally build up the entire dp table using  a loop and using a generalizing formula
    // dp[i]=max(dp[i-2]+a[i], dp[i-1])

    for(int i=4;i<=n;i++){
        dp[i]=max(dp[i-2]+arr[i],dp[i-1]);
    }
    
    // Print dp[n] which is the maximum non adjancent sum till index n
    cout<<"dp[n] "<<dp[n];

}