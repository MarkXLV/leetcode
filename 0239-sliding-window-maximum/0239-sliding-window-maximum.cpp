class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            while(!dq.empty() and nums[i]>dq.back())
            {
                dq.pop_back();
            }

            dq.push_back(nums[i]);

            if(i>=k)
            {
                if(dq.front()==nums[i-k])
                    dq.pop_front();
            }
            if(i>=k-1)
            {
                res.push_back(dq.front());
            }
        }
        return res;
    }
};