class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>res;
        unordered_set<int>dup;
        // seen during i'th iteration
        unordered_map<int,int>seen;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(dup.insert(nums[i]).second)
            {
                for(int j=i+1;j<n;j++)
                {
                    int sum=-nums[i]-nums[j];
                    auto it=seen.find(sum);
                    if(it!=end(seen) && it->second==i)
                    {
                        vector<int>temp={nums[i],nums[j],sum};
                        sort(temp.begin(),temp.end());
                        res.insert(temp);
                    }
                    seen[nums[j]]=i;
                }
            }
           
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
};