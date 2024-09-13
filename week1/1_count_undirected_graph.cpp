class Solution {
  public:
    long long count(int n) {
        int edges= n*(n-1)/2;
        return pow(2,edges);
    }
};
// time o(1)
// space o(1)

// The number of undirected graphs that can be constructed from 𝑛
// n vertices (not necessarily connected) is equivalent to the number of ways you can choose to include or exclude each edge between pairs of vertices.

// For n vertices, the number of possible edges is given by the binomial coefficient n(n-1)/2
//Each edge can either be present or absent in the graph, so for each possible edge, there are 2 choices. 
//Therefore, the total number of undirected graphs is pow(2,edges);