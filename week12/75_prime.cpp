//Prime Factors
public:
bool isP(int n)
{
    int count=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0){
            count++;
            if(n/i!=i) count++;
        }
    }
    if(count==2) return true;
    return 0;
}
vector<int>AllPrimeFactors(int N) {
    // Code here
    vector<int> a;
    for(int i=2;i*i<=N;i++)
    {
        if(N%i==0)
        {
            if(isP(i)) a.push_back(i);
            if(N/i!=i && isP(N/i)) a.push_back(N/i);
        }
    }
    if (isP(N)) a.push_back(N);
    return a;
} //TC O(root n * root n)
//********************************************************** */

bool isP(int n)
{
    int count=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0){
            count++;
            if(n/i!=i) count++;
        }
    }
    if(count==2) return true;
    return 0;
}
	
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    
	    vector<int> a;
	    for(int i=2;i*i<=N;i++)
	    {
	        if(N%i==0)
	        {
	            a.push_back(i);
                while(N%i==0)	        
	            N=N/i;
	        }
	    }
	    if (isP(N)) a.push_back(N);
	    return a;
	}
//TC O(root n * log n)