// find the element with maximum and minimum frequemcy
#include <bits/stdc++.h>

using namespace std;

void findMinMaxFrequencyElement(vector<int> arr)
{

    int size = arr.size();

    int maxOccuringElement, FreqMax = INT_MIN, minOccuringElement, FreqMin = INT_MAX;
    unordered_map<int, int> mpp;

    for (int i = 0; i < size; i++)
    {
        mpp[arr[i]]++;
        FreqMax=max(FreqMax,mpp[arr[i]]);
        FreqMin=min(FreqMin,mpp[arr[i]]);
    }

    for(auto pair: mpp){  
        if(pair.second==FreqMax) maxOccuringElement=pair.first;
        if(pair.second==FreqMin) minOccuringElement=pair.first;
    }

    cout<<"Max occuring Elemets is "<<maxOccuringElement<<"occuring for "<<FreqMax<<" times"<<endl;
    cout<<"Minimum occuring element is "<<minOccuringElement<<"occuring for"<<FreqMin<<" times"<<endl;

}

int main(){

    vector<int> arr={1,22,2,3,22,22,77,78,89,78};

    findMinMaxFrequencyElement(arr);



}