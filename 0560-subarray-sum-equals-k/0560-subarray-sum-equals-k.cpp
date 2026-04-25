class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pre(n,0);
        unordered_map<long long,long long>mp;
        long long ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            pre[i]=nums[i]+(i>=1?pre[i-1]:0);
            long long req=pre[i]-k;
            ans+=mp[req];
            mp[pre[i]]++;
        }
        return ans;
    }
};