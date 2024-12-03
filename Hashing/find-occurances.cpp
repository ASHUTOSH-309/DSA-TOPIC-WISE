#include<bits/stdc++.h>

using namespace std;



int main(){

// we have to read one array
// after that read queries

vector<int> nums;


int n;
cout<<"Enter the number of numbers to read: ";
cin>>n;
cout<< "Enter" <<n<<"numbers: ";

for(int i=0;i<n;i++){
    int temp;
    cin>>temp;
    nums.push_back(temp);
}


for(auto it : nums) cout<<it<<"\t";

int q;
cout<<"Enter the number of queries :";
cin>>q;


for(int i=0;i<q;i++){
    int temp;
    cin>>temp;
    // temp represents the current element being queried
    int count=0;
    // in brute force for each query just simply perform a linear search in order to find the count of the numbers

    for(int i=0;i<nums.size();i++){
        if(nums[i]==temp) count++;
    }
    cout<<"For query"<<temp<<" "<<count<<endl;

}






}