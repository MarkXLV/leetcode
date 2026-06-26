class Fenwick
{
    public:
        vector<int>bit;
        int n;

        Fenwick(int n)
        {
            this->n=n;
            bit.assign(n+1,0);
        }

        int query(int idx)
        {
            int sum=0;
            while(idx>0)
            {
                sum+=bit[idx];
                idx-=(idx&(-idx));
            }
            return sum;
        }

        void update(int idx,int val)
        {
            while(idx<=n)
            {
                bit[idx]+=val;
                idx+=(idx&(-idx));
            }
        }
};
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>prefix(n+1,0);
        for(int i=1;i<=n;i++)
        {
            prefix[i]+= prefix[i-1] + (nums[i-1]==target?1:-1);
        }
        vector<int>vals=prefix;
        // co-ordingate compression
        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(), vals.end()),
               vals.end());
        Fenwick bit(n);
        long long ans=0;
        for(auto x: prefix)
        {
            int rank=lower_bound(vals.begin(),vals.end(),x)-vals.begin()+1;
            ans+=bit.query(rank-1);
            bit.update(rank,1);
        }
        return ans;
    }
};