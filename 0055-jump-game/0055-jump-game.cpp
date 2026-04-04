class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int cmx=0;
        for(int i=0;i<n;i++)
        {
            if(i>cmx)return false;
            cmx=max(cmx,nums[i]+i);
        }
        return true;
    }
};