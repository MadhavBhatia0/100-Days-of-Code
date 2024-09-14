#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>> n>>m;
    int a[n+1][n+1];

    for(int i=0;i<m;i++)
    {  
        int u,v;
        cin >> u >> v;
        a[u][v]=1;
        a[v][u]=1;// no need to write this in case of directed graph
        // we can write weights instead of 1 in case of weighted graphs 
    }
    // space o(N^2)
    // use adjacency list
}