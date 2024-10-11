// LEETCODE 3 Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      vector < int > m(256, -1);
        int n=s.length();
        int l=0;
        int r=0;
        int maxlen=0;
        while(r!=n)
        {
            if (m[s[r]] >= l) {
            l = m[s[r]] + 1; 
            }
            m[s[r]]=r;
            maxlen = max(maxlen, r - l + 1);
           r++;
        }
        return maxlen;
    }
};
//USING HASHMAP and SLIDING WINDOW
// SC O(256)
// TC O(N)