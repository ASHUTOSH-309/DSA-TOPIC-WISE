#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    unordered_map<int, int> mpp;// will save space alot as compared to hasharray

    // Read n numbers and directly store their counts in the hashmap
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        mpp[temp]++;
    }

    int q;
    cin >> q;

    // read q queries and for each query just simply print the pre-computed count from the hashmap
    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;
        cout << mpp[temp] << " ";
    }
}