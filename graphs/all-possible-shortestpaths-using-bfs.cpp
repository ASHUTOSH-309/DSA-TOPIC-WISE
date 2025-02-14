#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    // input nodes and edges count

    ll n,m;
    cin>>n>>m;

    vector<ll> G[n+5];// adjacency list to map each node with its neighbour nodes

    for(ll i=1;i<=m;i++){
        cout<<"Enter new edge: ";
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }


    queue<ll> q;
    ll visited[n+1]={0};// initially each node is unvisited
    q.push(1);// push the root node
    visited[1]=1;

    ll level[n+1]={0};
    // we assume the level of the root node is zero

    ll ways[n+1]={0};
    ways[1]=1;// to reach src node 1 way

    while(!q.empty()){

        ll v=q.front();
        q.pop();

        for(ll neighbour: G[v]){

            if(visited[neighbour]==false){
                visited[neighbour]=true;
                q.push(neighbour);
                level[neighbour]=level[v]+1;
                ways[neighbour]=ways[v];
            }
            else{
                // now neighbour node may or may not be on the shortest path 
                // if it is then 
                if(level[neighbour]==level[v]+1){
                    // now the neighbour is on the shortest path, 1----v--neighbour shortest path is there
                    ways[neighbour]+=ways[v];
                }
                else{
                    // nothing to do as the path going with intermediate node as v does not comprise of the
                    // shortest path, it is a longer path
                }
            }
        }
    }

    // Done now ways array will contain the shortest path from each node to the source node,

    for(int i=1;i<=n;i++){
        //Assume the nodes to be 1 indexed
        cout<<"Node "<<i<<"Ways are "<<ways[i]<<endl;
    }

}