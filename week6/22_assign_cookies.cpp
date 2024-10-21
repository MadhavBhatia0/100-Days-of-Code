//LEETCODE 455 GREEDY METHOD
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0,r=0,count=0;
        while(l!=m && r!=n)
        {
            if(s[l]>=g[r])
            {
                count++;
                r++;
            }
            l++;
        }
        return count;
    }
};
// TC O(NLOGN+MLOGM)+O(MAX(N,M)) sorting+LOOP
// SC O(1)