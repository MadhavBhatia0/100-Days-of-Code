//leetcode 2220. Minimum Bit Flips to Convert Number
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int count=0;
        while(ans!=0){
            count++;
            ans=ans&(ans-1);
        }
        return count;
    }
};
//136. Single Number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            x^=nums[i];
        }return x;
    }
};

//78. Subsets
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> a;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++)  //total subsets 
        {
            vector<int> temp;
            for(int j=0;j<n;j++)  // total number of set bits in i_th number
            {
                if(i&(1<<j))
                {
                    temp.push_back(nums[j]);
                }
            }
            a.push_back(temp);
        }
        return a;
    }
};
// TC(2^n *n) 2loops
//  SC TC(2^n *n)

//using recursion
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    dfs(nums, 0, {}, ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& nums, int s, vector<int>&& path,
           vector<vector<int>>& ans) {
    ans.push_back(path);

    for (int i = s; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      dfs(nums, i + 1, move(path), ans);
      path.pop_back();
    }
  }

//gfg Find XOR of numbers from L to R
public:
  int xorUpto(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}
    int findXOR(int l, int r) {
        // complete the function here
        return xorUpto(r) ^ xorUpto(l - 1);
        
    }
    //TC O(1)
    //SC O(1)


//LEETCODE 137. Single Number II
//first approach is hashmap and count //O(N) FOR TRAVERSEL AND SPACE=O(N/3 +1)
// second approach is below
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int bit=0;bit<=31;bit++)
        {
            int count=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]&(1<<bit))
                count++;
            }
            if(count%3==1)
            ans+=(1<<bit);
        }
        return ans;
    }
};
// TC O(32*N)
// SC O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i+=3)
        {
            if(nums[i]!=nums[i-1]) return nums[i-1];
        }
        return nums[n-1];
    }
};
//TC O(NLOGN +N/3) better because nlogn ==n*32 only if we got an array size of 32
//SC O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0;
        int twos=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            ones=(ones^nums[i])&(~twos); //add in ones if not in twos
            twos=(twos^nums[i])&(~ones); // add in two if not in ones
        }
        return ones;
    }
};
//O(N)
//O(1)

//gfg single number 3
public:
    vector<long long int> twoOddNum(long long int nums[], long long int N)  
    {
        // code here
        int xorr=0;
        int n=N;
        for(int i=0;i<n;i++) xorr=xorr^nums[i];
        
        int rightmostbit=((xorr&(xorr-1))^xorr);
        
        int b1=0,b2=0;
        for(int i=0;i<n;i++){
            if(nums[i]&rightmostbit) b1^=nums[i];
            else b2^=nums[i];
        }
        int a=max(b1,b2);
        int b=min(b1,b2);
        vector<long long int> h={a,b};
        return h;
        
    }
//TC O(2N)
//SC O(1)
//A CASE OF INT_MIN WE HAVE TO USE LONG