class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp;
        for(auto x:nums)mp.insert(x);
        int ans=0;
        for(auto x:nums)
        {
            if(mp.find(x-1)==mp.end())
            {
                int cur=1;
                int k=x;
                while(mp.find(k+1)!=mp.end())
                {
                    k++;
                    cur++;
                }
                ans=max(ans,cur);
            }
        }
        return ans;

        
    }
};