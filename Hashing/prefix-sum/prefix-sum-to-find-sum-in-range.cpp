#include <bits/stdc++.h>

using namespace std;
void ProcessQueries(vector<int> nums,vector<pair<int,int>> queries){

    vector<int> PrefixSum(nums.size());

    long long sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        PrefixSum[i]=sum;
    }
    // So now the prefix array is generated 

    for(int i=0;i<queries.size();i++){
        // for each query extract left and right
        int left=queries[i].first;
        int right=queries[i].second;

        cout<<"For range "<<left<<" to "<<right<<endl;
        cout<<"Sum is: "<<PrefixSum[right]-PrefixSum[left-1]<<endl;
    }
}




int main()
{

    vector<int> nums={1,2,3,454,5,56,5};
    vector<pair<int, int>> queries={{3,5},{2,4},{0,2}};

    ProcessQueries(nums,queries);
}