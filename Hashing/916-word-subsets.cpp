#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& mainWords,vector<string>& requiredWords) {

        
        vector<string> UniversalStrings;
        unordered_map<char,int> MaxFreq;

        for(int i=0;i<requiredWords.size();i++){

            unordered_map<char,int> mpp;

            for(int j=0;j<requiredWords[i].size();j++){
                mpp[requiredWords[i][j]]++;
                MaxFreq[requiredWords[i][j]]=max( MaxFreq[requiredWords[i][j]],  mpp[requiredWords[i][j]]);
            }
        }


        for(int i=0;i<mainWords.size();i++){
            // all i which is a superstring{which contains atleast the characters in MaxFreq, or the occurence may be more that is a valid universal string}
            unordered_map<char,int> temp;

            for(int j=0;j<mainWords[i].size();j++){
                temp[mainWords[i][j]]++;
            }

            // Now compare the frequencies of current string with that of max Freq

            bool isUniversal=true;
            for(char ch='a';ch<='z';ch++){
                if(temp[ch]<MaxFreq[ch]){
                    isUniversal=false;
                    break;
                }
            }
            if(isUniversal) UniversalStrings.push_back(mainWords[i]);

        }


        return UniversalStrings;


    }
};