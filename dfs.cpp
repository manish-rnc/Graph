#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int v)
{
    cout << "Graph\n";
    for (int i = 0; i < v; i++)
    {
        cout << "[" << i << "]--";
        for (auto val : adj[i])
            cout << "-> " << val;
        cout << endl;
    }
}
void dfs(int v, vector<int> adj[], vector<bool> &visited, int start)
{
    if (!visited[start])
    {
        cout << start << " ";
        visited[start] = true;
        for (auto it : adj[start])
            dfs(v, adj, visited, it);
    }
}
void dfsOfGraph(int v, vector<int> adj[])
{
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)        // for disconnected graph
        dfs(v, adj, visited, i);

    // for loop is applied in case of disconnected graph because if loop is not applied then it will only print the vertices which
    // are connected to the starting vertex passed to the function
    // If the graph is connected, then no need to apply loop,function can be called simply by passing any vertex as starting vertex

    // Time complexity  : O(v+e)
    // Space Complexity : O(v)
}

// For counting the number of connected components
int noOfConnectedComponents(int v, vector<int> adj[])
{
    vector<bool> visited(v, false);
    int connectedComponents = 0;
    for (int i = 1; i < v; i++)
    {
        if (!visited[i])
        {
            connectedComponents++;
            dfs(v, adj, visited, i);
        }
    }
    return connectedComponents;
}

int main()
{

    // Disconnected Graph :
    //        0
    //      /   \       4
    //     1     2       \    
    //      \   /         5
    //        3

    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 3, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 5, 4);

    printGraph(adj, v);
    dfsOfGraph(v, adj);

    int count = noOfConnectedComponents(v, adj);
    cout << endl
         << "No of connected components : " << count << endl;

    return 0;
}