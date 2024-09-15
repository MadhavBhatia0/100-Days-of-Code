#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cin>> n>>m;
    vector<int> a[n+1]; //n+1 empty vectors
// we can write weights in pairs
// use vector<pair<int,int>> a[n+1];

    for(int i=0;i<m;i++)
    {  
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);// no need to write this in case of directed graph
        
    }
    // space o(2E) in unirected
    // space o(E) in directed graph
    // space o(4E) in weighted undirected graph
}

/* also a question on GeekforGeek
vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        int n=edges.size();
        vector<vector<int>> a(n);
        for(int i=0;i<n;i++)
        {
            int u=edges[i].first;
            int v=edges[i].second;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        return a;
*/