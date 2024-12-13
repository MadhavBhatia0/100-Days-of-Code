//gfg 
public:
  map<int,int> mpp;
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int n, int P) {
        // do modify in the given array
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=P)
            mpp[arr[i]]++;
            arr[i]=0;
        }
        
        for(int i=0;i<=n;i++)
        {
            arr[i-1]=mpp[i];
        }
    }