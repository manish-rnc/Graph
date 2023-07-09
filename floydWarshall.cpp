#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void floyd_warshall(vector<vector<int>>&matrix)
{
    int n = matrix.size();

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                // if both are infinity adding up them may cause integer overflow so they are checked before addition
                // Also INF is equivalent to INF - x (x being any integer value)
                if(matrix[i][k] != INF and matrix[k][j] != INF)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{0,1,43},{1,0,6},{INF,INF,0}};
    floyd_warshall(matrix);
    for(auto i : matrix)
    {
        for(auto it : i)
        {
            if(it == INF) cout<<"INF ";
            else cout<<it<<"   ";
        }
        cout<<endl;
    }

    return 0;    
}