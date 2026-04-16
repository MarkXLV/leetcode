class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums)
            mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(auto [key,freq]:mp)
        {
            pq.push({freq,key});
            // cout<<f<<k<<endl;
            if(pq.size()>k)
                pq.pop();
            
            // cout<<pq.size()<<endl;
        }
        vector<int>res;
        // cout<<pq.size()<<endl;
        while(!pq.empty())
        {
            auto x=pq.top();pq.pop();
            // cout<<x.second<<endl;
            res.push_back(x.second);
        }
        return res;
    }
};