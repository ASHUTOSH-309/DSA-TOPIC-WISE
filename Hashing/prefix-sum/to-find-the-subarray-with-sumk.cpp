#include <bits/stdc++.h>
using namespace std;

int FindSubArrayWithSumK(vector<int> nums, int k)
{

    int size = nums.size();
    unordered_map<int, int> PrefixSumFreq;

    long long sum = 0;
    PrefixSumFreq[0] = 1;

    long long count=0;
    for (int i = 0; i < size; i++)
    {
        sum += nums[i];

        // in the i th iteration, hashmap contains frequency of all distinct prefix sums from 0 to i-1
        if(PrefixSumFreq.find(sum-k)!= PrefixSumFreq.end()){
            count+=PrefixSumFreq[sum-k];
        }

        PrefixSumFreq[sum]++;
    }

    cout<<count;
    return count;
}


int main(){

    vector<int> arr={1,2,3,4,5,6,7,6,1,5};
    int k=6;

    FindSubArrayWithSumK(arr,k);




}
