class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        sort(intervals.begin(),intervals.end());

        int n=queries.size();
        vector<pair<int,int>>Query;
        for(int i=0;i<n;i++)
        {
            Query.push_back({queries[i],i});
        }
        sort(Query.begin(),Query.end());

        vector<int>res(n,-1);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        int intervalIdx=0;
        for(auto &[q,idx]:Query)
        {
            while(intervalIdx<intervals.size() && intervals[intervalIdx][0]<=q)
            {
                int start=intervals[intervalIdx][0];
                int end=intervals[intervalIdx][1];
                int size=end-start+1;
                pq.push({size,end});
                intervalIdx++;
            }
            while(!pq.empty() && pq.top().second<q)
            {
                pq.pop();
            }

            if(!pq.empty())
            {
                res[idx]=pq.top().first;
            }

        }
        return res;
    }
};