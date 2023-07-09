#include<bits/stdc++.h>
using namespace std;

// All pair shortest path algorithm
// Finding the shortest path between all possible pairs in a graph
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) 
{
    vector<int> d(V,1e9);
    d[S] = 0;
    
    for(int i=0;i<V-1;i++)
        for(auto i : edges)
            if( (d[i[0]] + i[2]) < d[i[1]])
                d[i[1]] = d[i[0]] + i[2];
    
    bool negCycle = false;
    for(int i=0;i<V-1;i++)
        for(auto i : edges)
            if( (d[i[0]] + i[2]) < d[i[1]])
                negCycle = true;
                
    if(negCycle)    
        return {-1};
    return d;
}
int main()
{
    int v = 3,source = 2;
    vector<vector<int>> edges = {{0,1,5},{1,0,3},{1,2,-1},{2,0,1}};
    vector<int> dist = bellman_ford(v,edges,source);
    for(auto it : dist)
        cout<<it<<" ";
    cout<<endl;    

    return 0;
}