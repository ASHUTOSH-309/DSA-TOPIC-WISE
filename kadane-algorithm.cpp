#include <bits/stdc++.h>

using namespace std;

int FindMaxSubArraySum(vector<int> arr)
{

    long long maxi = INT_MIN;
    long long sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        sum += arr[i];
        maxi = max(maxi, sum);
        if (sum < 0) sum = 0;
    }

    cout<<"Max sum in the array is"<<sum;

    return sum;
}


int main(){

    vector<int> arr={1,3,3,4,4,-10,-20,55,56};

FindMaxSubArraySum(arr);


}