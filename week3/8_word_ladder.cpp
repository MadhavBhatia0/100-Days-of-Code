// Leetcode 127. Word Ladder
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front().first;
            int d=q.front().second;
            q.pop();
            if(word==endWord)
            return d;
            for(int i=0;i<word.length();i++)
            {
                char originalchar=word[i];
                for(char j='a';j<='z';j++)
                {
                    if(word[i]!=j)
                    {
                    word[i]=j;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,d+1});
                    }
                    }
                }
                word[i]=originalchar;
            }
        }
        return 0;
    }
};
// TC queue *word length *26=O(N*wordLength*26)
// SC queue set =O(N)
// find in ordered set takes O(log N)