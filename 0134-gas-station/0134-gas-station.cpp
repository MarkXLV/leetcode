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
        cout<<endl;
        if(sum<0)return -1;
        int idx=0;
        int curr=0;
        for(int i=0;i<gas.size();i++)
        {
            curr+=gas[i];
            
            if(curr<0)
            {
                idx=i+1;
                curr=0;
            }
        }
        return idx;
    }
};