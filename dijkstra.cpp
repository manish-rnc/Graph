#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V,INT_MAX);
    dist[S] = 0;
    set<pair<int,int>> s;
    s.insert({0,S});
        
    while(!s.empty())
    {
        pair<int,int> p = *s.begin();
        int srcWt = p.first;
        int src = p.second;
        s.erase(s.begin());
        for(auto it : adj[src])
        {
            int node = it[0];
            int weight = it[1];
            if( (srcWt + weight) < dist[node] )
            {
                dist[node] = srcWt + weight;
                s.insert({dist[node],node});
            }
        }
    }
        
    return dist;
}

int main()
{
    int V=2,S=0;
    vector<vector<int>> adj[V] = {{{1, 9}}, {{0, 9}}};
    vector<int> ans = dijkstra(V,adj,S);
    for(auto it:ans)
        cout<<it<<" ";
    cout<<endl;    

    return 0;
}