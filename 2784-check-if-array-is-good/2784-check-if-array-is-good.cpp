class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        unordered_map<int,int>mp;
        for(auto x:nums)
        {
            sum+=x;
            mp[x]++;
            if(mp[x]>=2 and x!=n-1)
                return false;
        }
        return sum==(n*(n+1)/2 -1);
    }
};