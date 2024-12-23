#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int node, vector<vector<int>> adj, vector<bool> visited)
{

    queue<pair<int, int>> q;
    q.push({node, -1}); // -1 as source node is assumed to have no parent
    visited[node] = true;

    while (!q.empty())
    {

        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode : adj[node])
        {
            if (!visited[adjacentNode])
            {
                visited[adjacentNode] = true;
                q.push({adjacentNode, node});
            }
            else if (adjacentNode != parent)
            {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(vector<vector<int>> &adj)
{

    // Code here

    vector<bool> visited(adj.size(), 0);


// Loop to handle multiple connected components
    for (int i = 0; i < adj.size(); i++)
    {
        if (detectCycle(i, adj, visited))
        {
            return true;
        }
    }

    return false;
}