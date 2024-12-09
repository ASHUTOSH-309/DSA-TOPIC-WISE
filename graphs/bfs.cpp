#include <bits/stdc++.h>

using namespace std;

int main()
{

    int vertex;
    int edges;

    cin >> vertex >> edges;

    vector<int> adj[vertex]; // vertices are 0 indexed
    vector<bool> visited(vertex, false);

    // Take input for the graph
    // read all edges, an edge is just combination of two nodes

    for (int i = 0; i < edges; i++)
    {

        int x, y;
        cin >> x >> y;
        // graph is undirected so x--->y and y----> x
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // perform traversal over the graph bfs
    int src = 0;
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {

        // Extract the node from front
        int removed = q.front();
        cout << "Removed Node is " << removed << endl;
        q.pop();
        // Now iterate over neighbours of the removed node, which can be obtained form the adjancency matrix
        for (auto neighbour : adj[removed])
        {

            if (visited[neighbour] == false)
            {
                q.push(neighbour);         // Push into the queue
                visited[neighbour] = true; // Mark it as visited
            }
        }
    }
}