#include<bits/stdc++.h>
using namespace std;


int main(){
     // Writing output to STDOUT
	int n;
	cin>>n;

	int e;
	cin>>e;

    int i=1;

	vector<int> adj[n+1];

	while(i<=e){
		int x,y;
		cin>>x>>y;

		adj[x].push_back(y);
		adj[y].push_back(x);

		i++;
	}

	int src;
	cin>>src;


	// just perform bfs maintaining a simple level array

   int level[n+1]={0};
   level[src]=0;// Level of src is assumed to be zero

   queue<int> q;
   q.push(src);

   vector<bool> vis(n+1,false);
   vis[src]=true;

   while(!q.empty()){

		int curr=q.front();
		q.pop();

		for(int nebr: adj[curr]){
			if(vis[nebr]==false){
				vis[nebr]=true;
				q.push(nebr);
				level[nebr]=level[curr]+1;
			}
		}

   }

	bool flag=false;
   for(int dist: level){
     
	 if(flag)
	   cout<<dist<<" ";
	 flag=true;   
   } 
	

   return 0;

}
