class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum=0;
        int k=0;
        sort(cost.rbegin(),cost.rend());
        int idx=2;
        for(int i=0;i<cost.size();i++)
        {
            sum+=cost[i];
            if(i==idx)
            {  
              k+=cost[i];
              idx+=3;
            }
        }
        return sum-k;
    }
};