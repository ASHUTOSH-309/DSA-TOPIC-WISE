#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool CheckBipartite(int start, vector<int>& color,
                        vector<vector<int>>& graph) {

        queue<int> q;
        q.push(start);

        color[start] = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto adjacentNode : graph[node]) {

                if (color[adjacentNode] == -1) {
                    color[adjacentNode] = (color[node] == 0) ? 1 : 0;
                    q.push(adjacentNode);
                } else if (color[adjacentNode] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int nodes = graph.size();
        vector<int> color(nodes, -1);

        for (int i = 0; i < nodes; i++) {
            if (color[i] == -1) {
                if (CheckBipartite(i, color, graph) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};