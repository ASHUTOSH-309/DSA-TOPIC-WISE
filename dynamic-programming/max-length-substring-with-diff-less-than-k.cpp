#include<bits/stdc++.h>

using namespace std;


int main(){

    int n;
    cin>>n;// Input the string size
    int k;
    cin>>k;// Input k , in the max length for any i, j indices abs(s[i]-s[j])<=k

    string s;
    cin>>s;
    s+='$'; // Dummy character to ensure 1 based indexing

    vector<int> dp(n+1);// dp[i] implies max length ending at i with no adjacent 

    dp[1]=1;
    
    int maxi=1;// Assuming atleast n>=1
    for(int i=2;i<=n;i++){
        if(abs(s[i]-s[i-1])<=k){
           dp[i]=dp[i-1]+1;
            maxi=max(maxi,dp[i]);
        }       
        else dp[i]=1;
    }

    // As the max length string can end on any of the indices, hence max(dp[i]) will give us the answer

    cout<<maxi;// Output the max length of string with no adjacent character

}