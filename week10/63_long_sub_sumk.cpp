//gfg Longest Sub-Array with Sum K

//only works for positive A[i]
public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        // Complete the function
        map<int,int>mpp;
        int maxlen=0;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum==k)
            maxlen=max(maxlen,i+1);
            else{
                if(mpp.find(sum-k)!=mpp.end()){
                    maxlen=max(maxlen,i-mpp[sum-k]);
                }
            }
            mpp[sum]=i;
        }
        return maxlen;
    }

//works for +ve,-ve,0
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        // Complete the function
        map<int,int>mpp;
        int maxlen=0;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum==k)
            maxlen=max(maxlen,i+1);
            else{
                if(mpp.find(sum-k)!=mpp.end()){
                    maxlen=max(maxlen,i-mpp[sum-k]);
                }
            }
            if(mpp.find(sum)==mpp.end()) // if it doesnot exist in mpp before only then put it
            mpp[sum]=i;
        }
        return maxlen;
    }
    //O(N*LOGN) finding n elements in ordered mpp
    //O(N*1) if we use ordered mpp and in the worst case O(N*N)
    //SC O(N) for every index


//2 pointer approach
// only for +ve and 0
public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
    } 