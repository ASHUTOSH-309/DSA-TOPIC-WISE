#include <bits/stdc++.h>

using namespace std;

int main()
{

    unordered_set<int> st;
    int arr1[] = {2, 3, 34, 56};
    int arr2[] = {34, 56,67};// tweak the values in both to cross check

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr1[0]);


    for(int i=0;i<4;i++) st.insert(arr1[i]);// push all the unique elements of arr1 in the hashset


    // check whether arr2 is the subset of arr1
    for (int i = 0; i < size2; i++)
    {
        // iterate over each element of arr2 and check whether it is present in the hashset
        if(st.find(arr2[i])==0){
            // if any element is found which does not exist in the hashset, then it implies that the 
            // element is not present in arr1 hence arr2 can't be the subset
            cout<<"Not a Subset"<<endl;
            return 0;
        }
    }

    cout<<"is a subset as all elements of arr2 is present in arr1 also"<<endl;

    return 0;


}