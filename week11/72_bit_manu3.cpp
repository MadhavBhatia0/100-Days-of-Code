//LEETCODE 50.Pow(x, n)
class Solution {
public:
    double myPow(double x, long n) {
        if(n==0||x==1)
        return 1;
        if(n>0){
            if(n%2==1)
        return x*myPow(x,n-1);
        return myPow(x*x,n/2);
        }
        return 1/myPow(x,-n);
    }
};
//TC O(LOGN);
//SC O(LOGN);