#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> arr1(n + 1);
    vector<int> arr2(n + 1);

    cout << "Now Input " << n << " numbers for arr1 ";
    for (int i = 1; i <= n; i++) cin >> arr1[i];

    cout << "Now Input " << n << " numbers for arr2 ";
    for (int i = 1; i <= n; i++) cin >> arr2[i];

    vector<int> dp(n + 1); // dp[i]--> max subset sum achievable till index i

    dp[1] = max(arr1[1], arr2[1]);
    dp[2] = max(max(arr1[1], arr2[1]), max(arr1[1], arr2[1]));


    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-1],max(arr1[i],arr2[i])+dp[i-2]);
    }

    cout<<"Max Subset Sum till index n is "<<dp[n];

}