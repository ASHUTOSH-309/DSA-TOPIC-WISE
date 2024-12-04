#include<bits/stdc++.h>

using namespace std;


bool CheckDuplicatesWithinK(vector<int> arr, int k){

    int size=arr.size();
// arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
    unordered_map<int,int> mpp;

    for(int currentIndex=0;currentIndex<size;currentIndex++){
        
        if(mpp.find(arr[currentIndex]) != mpp.end()){
           // the key exists then fetch its value
            int previousIndex=mpp[arr[currentIndex]];
            if(currentIndex-previousIndex >k){
                    // the last occurence of currentElement was not in previous k cells
                    // just update map with the greatest position till now
                    mpp[arr[currentIndex]]=currentIndex;
            }
            else{
                // if the current Element has a redundant element in the previous k cells then simply return true
                return true;

            }
        }
    } 

        




}