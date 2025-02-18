public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int count=0;
        int maxcnt=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0;
        
        while(i<n)
        {
            if(arr[i]<=dep[j])
            {
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            maxcnt=max(maxcnt,count);
        }
        return maxcnt;
    }