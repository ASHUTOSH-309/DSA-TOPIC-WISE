#include <bits/stdc++.h>

using namespace std;

int makeArrayEqual(vector<int> arr)
{
    // You are allowed to perform mdas on any number

    // crux is find that number whose frequecy is max, let it remain
    // unchanged and change the rest performing a single operation

    int maxi = 1;
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
        maxi=max(maxi,mpp[arr[i]]);
    }
// maxi itself contains the highest frquency so far, directly subtract from the total size in order to get the answer
    cout<<arr.size()-maxi;
}