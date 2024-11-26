// gfg bit manupulation
public:
    void bitManipulation(int num, int i) {
        // your code here
        int temp=num;
        int bit=0;
        for(int j=1;j<=i;j++)
        {
            bit=temp%2;
            temp=temp/2;
        }
        cout<<bit<<" ";
        
        if(bit) cout<<num<<" "<<num-pow(2,i-1);
        else cout<<num+pow(2,i-1)<<" "<<num;
        
    }

void bitManipulation(int num, int i) {
        // Get the ith bit
        int getBit = (num >> (i - 1)) & 1;

        // Set the ith bit
        int setBit = num | (1 << (i - 1));

        // Clear the ith bit
        int clearBit = num & ~(1 << (i - 1));

        // Print the results in required format
        std::cout << getBit << " " << setBit << " " << clearBit;
    }
    // TCO(1)
    // SC O(1)

//Odd or Even
public:
    string oddEven(int n) {
        // code here
        if(n&1) return "odd";
        return "even";
    }

// leetcode 231 Power of 2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n & (n-1)) return false;
        return true;
    }
};

//gfg Count total set bits
public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        if(n<=0) return 0;
        int count=0;
        for(int j=1;j<=n;j++)
        {
            count+=__builtin_popcount(j);
        }
        return count;
    }

public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        if (n == 0) return 0;

        // Find the highest power of 2 less than or equal to n
        int x = log2(n); //leftmost 1

        // Formula to calculate the number of set bits from 1 to the highest power of 2 less than or equal to n
        int bitsTill2x = x * (1 << (x - 1));

        // Calculate the number of set bits from the remaining numbers after the highest power of 2
        int msbFrom2xtoN = n - (1 << x) + 1;

        // Recursively count set bits for the remaining numbers
        int remaining = n - (1 << x);

        return bitsTill2x + msbFrom2xtoN + countSetBits(remaining);
    }
//self written    
int countSetBits(int n)
    {
        // Your logic here
        if(n==0) return 0;
        
        int x=log2(n);
        
        int untilnear2power=x*(1<<(x-1));
        int totalmsb=n-(1<<x)+1;
        int remaining=n&(~(1<<x));
        return untilnear2power+totalmsb+countSetBits(remaining);
    }

//Set the rightmost unset bit
public:
    int setBit(int n) {
        // Write Your Code here
        return ((n+1)|(n));
    }

//Swap two numbers
pair<int, int> get(int a, int b){
        //complete the function here
        a=a^b;
        b=a^b;
        a=a^b;
        return {a,b};
    }

//LEETCODE 29. Divide Two Integers
class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend==divisor)
      return 1;
    int sign=1;
    if(dividend<0 &&divisor>=0) sign=-1;
    if(dividend >=0 && divisor<0) sign=-1;

    long ans = 0;
    long n = abs(dividend);
    long d = abs(divisor);

    while (n >= d) {
      int count=0;
      while (n>= (d<<(count+1))) count++;

      ans+=(1<<count);
      n-=(d<<count);
    }
    if(ans==(1<<31)&& sign==1) return INT_MAX;
    if(ans==(1<<31)&& sign==-1) return INT_MIN;

    return sign * ans;
  }
};