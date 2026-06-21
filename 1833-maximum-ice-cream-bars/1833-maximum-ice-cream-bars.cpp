class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>cnt(1e5+1,0);
        for(auto x:costs)
        {
            cnt[x]++;
        }
        int ans=0;
        for(int i=0;i<1e5+1;i++)
        {
            if(cnt[i]>0)
            {
                int rem=coins/i;
                if(rem>=cnt[i])
                {
                    ans+=cnt[i];
                    coins-=cnt[i]*i;
                }else
                {
                    ans+=rem;
                    coins-=rem*i;
                    break;
                }
            }
        }
        return ans;
    }
};