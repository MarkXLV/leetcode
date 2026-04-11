class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            gas[i]=gas[i]-cost[i];
            sum+=gas[i];
        }
        if(sum<0)return -1;
        int ans=0;
        int idx=0;
        int curr=0;
        int mx=0;
        for(int ii=0;ii<2*gas.size();ii++)
        {
            int i=ii%n;
            curr+=gas[i];
            if(curr<0)
            {
                idx=i+1;
                curr=0;
            }else
            {
                if(curr>mx)
                {
                    mx=curr;
                    ans=idx;
                }
            }
        }
        return ans;
    }
};