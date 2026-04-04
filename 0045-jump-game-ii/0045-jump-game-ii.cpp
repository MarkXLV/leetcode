class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int ans=0;
        int cmx=0;
        int mxx=0;
        for(int i=0;i<n-1;i++)
        {
            cmx=max(cmx,nums[i]+i);
            if(i==mxx)
            {
                ans++;
                mxx=cmx;
            }
        }
        return ans;
    }
};