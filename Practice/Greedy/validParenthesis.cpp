//678. Valid Parenthesis String
class Solution {
    public:
        bool checkValidString(string s) {
            int min=0,max=0;
            for(int i=0;i<s.length();i++)
            {
                if(min==-1 || max ==-1) return 0;
                switch(s[i]){
                    case '(':
                    min++; max++; break;
                    case ')':
                    if(min>0) min--;
                    max--; break;
                    case '*':
                    if(min>0) min--;
                    max++;
                }
            }
            if(min==-1 || max ==-1) return 0;
            if(min==0) return 1;
            return 0;
        }
    };
    // Time Complexity: O(n)
    // Space Complexity: O(1)