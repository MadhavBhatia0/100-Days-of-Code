//gfg largest element 
public:
    int largest(vector<int> &arr) {
        // code here
        int m=arr[0];
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]>m)
            m=arr[i];
        }
        return m;
    } //tc o(N)