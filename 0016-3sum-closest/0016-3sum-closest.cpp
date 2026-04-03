class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            if(i==0 || nums[i]!=nums[i-1])
            {
                int k=solve(i,nums,target);
                if(abs(target-k)<(abs(target-ans)))
                {
                    ans=k;
                }
            }
        }
        return ans;
    }

    int solve(int i,vector<int>& nums, int target)
    {
        int ans=1e9;
        for(int j=i+1;j<nums.size();j++)
        {
            int l=j,r=nums.size()-1;
            while(l<r)
            {
                int closest_target=nums[i]+nums[l]+nums[r];
                if(abs(target-closest_target)<(abs(target-ans)))
                {
                    ans=closest_target;
                }
                if(closest_target==target)
                {
                    return target;
                }else if(closest_target>target)
                {
                    r--;
                }else
                {
                    l++;
                }
            }
        }
        return ans;
    }
};