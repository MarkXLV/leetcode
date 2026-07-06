class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& interval) {
        int ans=interval.size();
        sort(interval.begin(),interval.end(),[](const vector<int>&a,const vector<int>&b)
        {
            if(a[0]==b[0])
            {
                return a[1]>b[1];
            }else
            {
                return a[0]<b[0];
            }
        });

        int end=interval[0][1];
        for(int i=1;i<interval.size();i++)
        {
            if(interval[i][1]<=end)
            {
                ans--;
            }else
            {
                end=interval[i][1];
            }
        }
        return ans;

    }
};