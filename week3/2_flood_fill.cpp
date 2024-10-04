// leetcode 733
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int temp= image[sr][sc];

        bfs(image,sr,sc,color,temp);
        return image;
    }
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,int temp)
    {
        if(sr<0 || sc <0 || sr >= image.size() || sc >= image[0].size())
        return;
        
        int t=image[sr][sc];
        if(temp!=t || t==color)
        return;

        image[sr][sc]=color;

        int r[4]={-1,0,1,0};
        int c[4]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            bfs(image,sr+r[i],sc+c[i],color,temp);
        }
    }
};
// space O(N*M) stack space
// time O(N*M)  bfs on all nodes