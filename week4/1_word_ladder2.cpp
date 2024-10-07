// leetcode 126
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        vector<vector<string>> a;
        queue<vector<string>> q;
        int level=0;
        vector<string> qlevel;
        qlevel.push_back(beginWord);
        q.push({beginWord});

        while(!q.empty())
        {
            vector<string> b=q.front();
            q.pop();

            if(level< b.size())
            {
                level++;
                for(auto it : qlevel)
                {
                    st.erase(it);
                }
            }

            string word=b.back();
            if(word==endWord)
            {
                if(a.size()==0)
                {
                    a.push_back(b);
                }
                else if(a[0].size() == b.size())
                {
                    a.push_back(b);
                }
            }
            for(int i=0;i<word.size();i++)
            {
                char originalchar=word[i];
                for(char j='a';j<='z';j++)
                {
                    word[i]=j;
                    if(st.count(word)>0)
                    {
                        b.push_back(word);
                        q.push(b);
                        qlevel.push_back(word);
                        b.pop_back();
                    }
                }
                word[i]=originalchar;
            }
        }
        return a;
    }
};