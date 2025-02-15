//gfg
class Solution {
    public:
      // Function to get the maximum total value in the knapsack.
      static bool comp(pair<int,int> a, pair<int,int> b)
      {
          double fr1=(double)a.first/a.second;
          double fr2=(double)b.first/b.second;
          
          if(fr1>fr2) return true;
          return false;
      }
      double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          // Your code here
          vector<pair<int,int>> a;
          int n=val.size();
          double op=0;
          for(int i=0;i<n;i++)
          {
              a.push_back({val[i], wt[i]});
          }
          sort(a.begin(), a.end(), comp);
          for(int i=0;i<n;i++)
          {
              if(capacity>=a[i].second)
              {
                  capacity-=a[i].second;
                  op+=a[i].first;
              }
              else{
                  double value=((double)a[i].first/a[i].second)*capacity;
                  op+=value;
                  break;
              }
          }
          return op;
      }
// Time Complexity: O(NlogN)
// Space Complexity: O(N)