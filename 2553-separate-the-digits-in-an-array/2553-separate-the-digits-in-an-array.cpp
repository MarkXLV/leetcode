class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--)
        {
            int k=nums[i];
            while(k>0)
            {
                int digit=k%10;
                k/=10;
                ans.push_back(digit);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};