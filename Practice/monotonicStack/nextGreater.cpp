//496. Next Greater Element I
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            vector<int> ans;
            unordered_map<int,int> mpp;
            stack<int> st;
            for(int i=0;i<nums2.size();i++)
            {
                while(!st.empty() && st.top()<nums2[i])
                {
                    mpp[st.top()]=nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
            for(int i=0;i<nums1.size();i++)
            {
                if(mpp.find(nums1[i])==mpp.end()) ans.push_back(-1);
                else ans.push_back(mpp[nums1[i]]);
            }
            return ans;
        }
    };
//tc-o(2n)
//sc-o(n)