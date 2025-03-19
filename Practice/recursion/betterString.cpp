public:
    string betterString(string s1, string s2) {
        // code here
        unordered_set<string> ss1;
        unordered_set<string> ss2;
        
        countt(s1,0,"",ss1);
        countt(s2,0,"",ss2);
        
        if(ss1.size()>=ss2.size()) return s1;
        return s2;
    }
    void countt(string s,int ind,string curr,unordered_set<string>& ss)
    {
        int si=s.length();
        if(si==ind)
        {
            ss.insert(curr);
            return;
        }
        countt(s,ind+1,curr+s[ind],ss);
        countt(s,ind+1,curr,ss);
    }



//using memo
int countSubsequences(string &s, int index, unordered_map<int, int> &lastOccurrence, unordered_map<int, int> &memo) {
    // Base case: If we reach the end, return 1 (empty subsequence)
    if (index == s.size()) {
        return 1;
    }
    
    // Check if result is already computed
    if (memo.find(index) != memo.end()) {
        return memo[index];
    }

    // Count subsequences excluding the current character
    int count = countSubsequences(s, index + 1, lastOccurrence, memo);

    // Count subsequences including the current character
    int newCount = count;
    if (lastOccurrence.find(s[index]) != lastOccurrence.end()) {
        newCount -= countSubsequences(s, lastOccurrence[s[index]] + 1, lastOccurrence, memo);
    }

    // Update last occurrence of the character
    lastOccurrence[s[index]] = index;

    // Store and return the result
    return memo[index] = count + newCount;
}

// Function to determine the better string
string betterString(string s1, string s2) {
    unordered_map<int, int> lastOccurrence1, lastOccurrence2, memo1, memo2;

    // Count distinct subsequences for both strings
    int count1 = countSubsequences(s1, 0, lastOccurrence1, memo1);
    int count2 = countSubsequences(s2, 0, lastOccurrence2, memo2);

    // Compare and return the string with more distinct subsequences
    return (count1 >= count2) ? s1 : s2;
}