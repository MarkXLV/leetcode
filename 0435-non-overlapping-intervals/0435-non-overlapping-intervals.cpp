class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int end=intervals[0][1];
        int n=intervals.size();
        int cn=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<end)
            {
                cn++;
                
            }else
            {
                end=intervals[i][1];
            }
        }
        return cn;
    }
};