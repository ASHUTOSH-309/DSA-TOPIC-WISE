#include <bits/stdc++.h>

using namespace std;

void MaxMinSubArrayWithLengthK(vector<int> arr, int k)
{

    int size = arr.size();
    int global_minima = INT_MAX;
    int global_maxima = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        long long sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                global_minima = min(global_minima, j - i + 1);
                global_maxima = max(global_maxima, j - i + 1);
            }
        }
    }

    cout << "max:" << global_maxima << endl;
    cout << "min:" << global_minima << endl;
}

int main()
{

    vector<int> arr = {1, 2, 3, 6, -6,0,0,0};
    int k = 6;
    MaxMinSubArrayWithLengthK(arr, k);
}