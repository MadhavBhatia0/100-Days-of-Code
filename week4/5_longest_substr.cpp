// LEETCODE 3 Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> m;
            for(int j=i;j<n;j++)
            {
                if(m[s[j]]==0)
                {
                    int temp=j-i+1;
                    maxlen=max(temp,maxlen);
                    m[s[j]]=1;
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }
};
// USING HASHMAP
// SC O(256)
// TC O(N*N) 2 LOOPS