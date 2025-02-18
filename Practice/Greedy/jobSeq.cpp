public:
  static bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.second > b.first.second) return true;  // Sort by profit (descending)
    if (a.first.second == b.first.second) return a.first.first < b.first.first;  // If profit is same, sort by deadline (ascending)
    return false;
}

    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        vector<pair<pair<int,int>,int>> a;
        int n=deadline.size();
        int maxDeadline=0;
        
        for(int i=0;i<n;i++)
        {
            pair<int,int> b={deadline[i],profit[i]};
            a.push_back({b,id[i]});
            maxDeadline = max(maxDeadline, a[i].first.first);
        }
        sort(a.begin(),a.end(),comp);
        vector<int> temp(maxDeadline+1, -1);
        
        int count=0;
        int p=0;
        
        for(int i=0;i<n;i++){
            int d=a[i].first.first;
            int profit=a[i].first.second;
            
            for(int j=d;j>0;j--)
            {
                if(temp[j]==-1)
                {
                    p+=profit;
                    temp[j]=1;
                    count++;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(p);
        return ans;
    }