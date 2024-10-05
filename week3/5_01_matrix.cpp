//leetcode 542. 01 Matrix
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
     int m=mat.size();
     int n=mat[0].size();
     vector<vector<int>> vis (m,vector<int>(n,0));
     vector<vector<int>> ans(m,vector<int>(n,0));

     queue<pair<pair<int,int>,int>> q;

     for(int i=0;i<m;i++)
     {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
                ans[i][j]=0;
                q.push({{i,j},0});
            }
        }
     }
     int r1[]={-1,0,1,0};
     int c1[]={0,-1,0,1};
     while(!q.empty())
     {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int d=q.front().second;
        q.pop();
        if(r>=0 && c >=0 && r<m && c<n && vis[r][c]==0){
            ans[r][c]=d;
            vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            q.push({{r+r1[i],c+c1[i]},d+1});
        }
        }
     }
    return ans;
    }
};
//SC VIS(M*N)+ANS(M*N)++QUEUE(M*N)=O(M*N)
//TC ONE LOOP FOR ALL NODES =O(M*N)