class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        int n=speed.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first>b.first;
        });
        stack<double>st;
        for(auto [p,s]:v)
        {
            double time=1.0*(target-p)/s;
            if(st.empty() || time>st.top())
            {
                st.push(time);
            }
        }
        return st.size();
    }
};