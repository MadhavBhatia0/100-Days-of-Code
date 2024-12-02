int gcd=1;
        int n=min(a,b);
        for(int i=n;i>=1;i++)
        {
            if(a%i==0 && b%i==0)
            {
                gcd=i;
                break;
            }
        }

int gcd=1;
        while(a>0 && b>0)
        {
            if(a>b) a=a%b;
            else    b=b%a;
        }
        if(a==0) gcd=b;
        else     gcd=a;
    } //TC= log of(min(a,b)) with base phi

long long gcd=1;
        long long a=c;
        long long b=d;
        while(a>0 && b>0)
        {
            if(a>b) a=a%b;
            else    b=b%a;
        }
        if(a==0) gcd=b;
        else     gcd=a;
        long long lcm=(c*d)/gcd;
        return {lcm,gcd};
    }