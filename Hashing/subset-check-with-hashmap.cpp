#include <bits/stdc++.h>
using namespace std;

bool checkForSubset(vector<int> v1, vector<int> v2){

    int m=v1.size();
    int n=v2.size();

    unordered_map<int,int> mpp;
    for(int i=0;i<m;i++){
            mpp[v1[i]]++;// create hashmap corresponding to list1
    }

    for(int i=0;i<n;i++){
       // if mpp[v2[i]] is non zero, it is not an obstruction in our path 
            if(mpp[v2[i]]==0){
                cout<<"Not a subset as"<<v2[i]<<"is not present in the list"<<endl;
                return false;
            }
    }

    return true;
}



int main()
{

    vector<int> v1={33, 45, 65 , 78};
    vector<int> v2={33, 45};


    if(checkForSubset(v1,v2)){

        cout<<"whoop you got a subset"<<endl;
    }
    else{

        cout<<"Bye";
    }

    
    return 0;



}
