#include<bits/stdc++.h>


using namespace std;

int main(){


    int n;
    cin>>n;
    vector<int> nums;
    vector<int> HashArray(51);// An hasharray to store the frequency of elements upto 50

// read numbers in an array
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
        HashArray[temp]++;
    }

    int q;
    cout<<"Enter the number of queries :";
    cin>>q;

// A loop to read the queries
cout<<"Enter" <<q <<"distinct queries each should range in between 0 to 50"<<endl; 
    for(int i=0;i<q;i++){
        int temp;
        cin>>temp;
        cout<<HashArray[temp]<<"\t";
    }
}