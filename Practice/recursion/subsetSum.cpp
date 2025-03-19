public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> sumarr;
        int n=arr.size();
        if(!n) return sumarr;
        
        int sum=0;

        f(0,n,sum,arr,sumarr);
        return sumarr;
    }
    void f(int ind,int n,int sum,vector<int>& arr,vector<int>& sumarr)
    {
        if(ind==n)
        {
            sumarr.push_back(sum);
            return;
        }
        f(ind+1,n,sum+arr[ind],arr,sumarr);
        f(ind+1,n,sum,arr,sumarr);
    }