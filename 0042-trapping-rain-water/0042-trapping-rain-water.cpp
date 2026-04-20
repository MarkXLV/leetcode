class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int lmax=0;
        int rmax=0;
        int ans=0;
        while(l<=r)
        {
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            if(lmax>rmax)
            {
                ans+=(min(lmax,rmax)-height[r]);
                r--;
            }else
            {
                ans+=(min(lmax,rmax)-height[l]);
                l++;
            }
        }
        return ans;
    }
};