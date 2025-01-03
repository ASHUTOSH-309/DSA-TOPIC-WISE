#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MAXI = 1000000;

vector<int> spf(MAXI, 1);

void ComputeSpf()
{
    for (int i = 2; i <= MAXI; i++) spf[i] = i;

    for (int i = 2; i * i <= MAXI; i++){
        if (spf[i] == i){//if i is a prime number
            for (int j = i * i; j < MAXI; j += i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}


unordered_map<ll,ll> PrimeFactors(ll val){

    unordered_map<ll,ll> mpp;
    while(val!=1){

        int spF=spf[val];
        mpp[spF]++;
        val=val/spF;
    }

    return mpp;
}

int main()
{

    ComputeSpf();

    int n;
    cin >> n;

    ll b[n+1]={0};

    for(int i=1;i<=n;i++){

        cin>>b[i];
        unordered_map<ll,ll> primeFactors=PrimeFactors(b[i]);
        
        // Now the prime factors of b[i] along with their correspomding frequemcies are stored in the map
        cout<<"Prime factors for "<<b[i]<< endl;
        for(auto it: primeFactors){
            cout<<it.first<<" "<<it.second<<" "<<endl;
        }
    }
}