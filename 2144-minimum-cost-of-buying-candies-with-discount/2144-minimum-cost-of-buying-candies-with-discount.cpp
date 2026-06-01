class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum=0;
        sort(cost.rbegin(),cost.rend());
        int idx=2;
        for(int i=0;i<cost.size();i++)
        {
            
            if(i==idx)
              idx+=3;
            else
              sum+=cost[i];
        }
        return sum;
    }
};