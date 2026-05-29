class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int x:nums)
        {
            int k=0;
            while(x>0)
            {
                k+=(x%10);
                x=x/10;
            }
            ans=min(ans,k);
        }
        return ans;
    }
};