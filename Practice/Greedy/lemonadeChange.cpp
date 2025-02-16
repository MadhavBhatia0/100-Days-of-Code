//LC 860. Lemonade Change
class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int c5=0,c10=0;
            for(int i=0;i<bills.size();i++)
            {
                switch(bills[i])
                {
                    case 5:
                     c5++; break;
                    case 10:
                    if(c5==0) return 0;
                    c10++;c5--;break;
                    default:
                    if(c5==0) return 0;
                    if(c10!=0)
                    {
                        c5--;c10--;
                    }
                    else if(c5>=3) c5-=3;
                    else return 0;
                }
            }
            return 1;
        }
    };
//O(n) TIME
//O(1) SPACE