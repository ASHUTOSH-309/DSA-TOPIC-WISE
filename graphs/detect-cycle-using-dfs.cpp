  #include<bits/stdc++.h>
  using namespace std;

  bool detectCycle(int node,int parent,vector<vector<int>>& adj, vector<bool>& visited){
        
        visited[node]=true;
        for(int neighbour: adj[node]){
            if(visited[neighbour]==false){
               if(detectCycle(neighbour, node, adj, visited)==true){
                 return true;  
               } 
            }
            else if(neighbour != parent){
                return true;
            }
            
        }
        
        return false;
    }
    
    
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
       vector<bool> visited(adj.size(),false);
       
       for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                if(detectCycle(i,-1,adj,visited)==true){
                    return true;
                }
            }
       }
        
        return false;
    }