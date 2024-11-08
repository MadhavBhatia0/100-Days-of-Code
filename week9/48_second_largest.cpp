// gfg Second Largest
int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        if(n<2) return -1;
        
        int m=min(arr[0],arr[1]);
        int m2=max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++)
        {
            if(arr[i]>m2)
            {
                m=m2;
                m2=arr[i];
            }
            else if(arr[i]>m && arr[i]!=m2)
            m=arr[i];
        }
        if(m!=m2)
        return m;
        return -1;
    }