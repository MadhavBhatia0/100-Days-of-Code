//gfg Undirected Graph Cycle
#include <vector>
#include <queue>
using namespace std;

bool detect(vector<int> adj[], int vis[], int src) {
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});  // Start BFS from the src node

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjn : adj[node]) {
            if (!vis[adjn]) {  // If adjacent node is not visited
                vis[adjn] = 1;
                q.push({adjn, node});
            } else if (adjn != parent) {  // If adjacent node is visited and it's not the parent, cycle found
                return true;
            }
        }
    }

    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    int vis[V]={0};

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {  // Check for every unvisited node
            if (detect(adj, vis, i))
                return true;
        }
    }

    return false;
}
// SC queue + vis = 2N+N =O(3N)
// TC NODES + total degree= O(N+2E)+O(N) main wala for loop(in worst case it will run for n times(disconnected graph))