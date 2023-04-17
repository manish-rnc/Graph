#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> adj;

public:
    Graph(int n)
    {
        adj.resize(n + 1);      // (n+1) for not considering the 0th index
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void printGraph()
    {
        cout << "Graph:" << endl;
        for (int i = 1; i < adj.size(); i++)
        {
            cout << "[" << i << "]--";
            for (auto x : adj[i])
                cout << "-> " << x;
            cout << endl;
        }
    }
    void bfs();
};
void Graph::bfs()
{
    int v = adj.size(), start = 1;     // start is the starting vertex  and  v is the number of vertex in the graph
    vector<bool> visited(v, false);
    queue<int> q;
    q.push(start);
    cout << start << " ";
    visited[start] = true;

    while (!q.empty())
    {
        int frontOfQueue = q.front();
        for (auto i : adj[frontOfQueue])
        {
            if (visited[i] != true)
            {
                cout << i << " ";
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }

    // Time complexity  : O(v+e)
    // Space complexity : O(v)
    // where v is the number of vertices or nodes and e is the number of edges
}

int main()
{
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.printGraph();
    g.bfs();

    return 0;
}