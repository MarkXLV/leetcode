class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mp;
        for(auto x:bills)
        {
            if(x!=5)
            {
                if(x==10)
                {
                    if(mp[5]>0)
                    {
                        mp[5]--;
                    }else
                    {
                        return false;
                    }
                }else
                {
                    if(mp[10]>0 and mp[5]>0)
                    {
                        mp[10]--;
                        mp[5]--;
                    }else if(mp[5]>=3)
                    {
                        mp[5]-=3;
                    }else
                    {
                        return false;
                    }
                }
            }
            mp[x]++;
        }
        return true;
    }
};