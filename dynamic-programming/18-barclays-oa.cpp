#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[100000][5];
int main()
{
    int n;
    cin >> n;

    vector<int> Easy(n + 1);
    vector<int> Hard(n + 1);

    // Read both the arrays
    for (int i = 1; i <= n; i++)
    {
        cin >> Easy[i];
        cin >> Hard[i];
    }

    // dp[i][j]--> on i th day j th task is selected then the max profit

    int EasyTask = 1;
    int HardTask = 2;
    int Haramkhori=3;
    dp[1][EasyTask] = Easy[1];
    dp[1][HardTask] = Hard[1];
    dp[1][Haramkhori]=0;

    for(int i=2;i<=n;i++){
        dp[i][EasyTask]=Easy[i] + max({dp[i-1][EasyTask], dp[i-1][HardTask],dp[i-1][Haramkhori]});
        dp[i][HardTask]=Hard[i] + dp[i-1][Haramkhori];
        dp[i][Haramkhori]= max({dp[i-1][EasyTask],dp[i-1][HardTask],dp[i-1][Haramkhori]});
    }


    cout<<max({dp[n][EasyTask],dp[n][HardTask],dp[n][Haramkhori]});
    
}