#include <bits/stdc++.h>
using namespace std;

bool CheckDuplicatesWithinK(vector<int> arr, int k)
{
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        //the inner loop will run for max of k times
        // TC---> O(size*k);
        for (int j = i + 1; j < size && j <= i + k; j++)
        {
            // if any duplicates is found in next k index for
            if (arr[i] == arr[j])
                return true;
        }
    }

    // if not found duplicates in k bounds for any element in the list then return false, no redundency in the next k
    // indices for any element
    return false;
}


