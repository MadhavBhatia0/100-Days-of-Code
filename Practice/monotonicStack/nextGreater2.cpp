//lc 503
class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n=nums.size();
            vector<int> a(n,-1);
    
            stack<int> st;
            for(int i=(2*n-1);i>=0;i--)
            {
                while(!st.empty() && st.top()<=nums[i%n])
                {
                    st.pop();
                }
                
                if(i<n)
                {
                    if(!st.empty() && nums[i%n]<st.top())
                    a[i]=st.top();
                    else a[i]=-1;
                }
                st.push(nums[i%n]);
            }
            return a;
        }
    };
//tc-o(4n)
//sc-o(3n)