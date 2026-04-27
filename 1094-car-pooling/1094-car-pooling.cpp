class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<pair<int,int>>pick;
        vector<pair<int,int>>drop;
        unordered_map<int,int>pickm;
        unordered_map<int,int>dropm;
        for(auto x:trips)
        {
            // pickm[x[1]]+=x[0];
            // dropm[x[2]]+=x[0];
            pick.push_back({x[1],x[0]});
            drop.push_back({x[2],x[0]});
        }

        // for(auto &[u,v]:pickm)
        // {
        //     pick.push_back({u,v});
        // }

        // for(auto &[u,v]:dropm)
        // {
        //     drop.push_back({u,v});
        // }

        sort(pick.begin(),pick.end());
        sort(drop.begin(),drop.end());
        int i=0;int j=0;
        while(i<pick.size() and j<drop.size())
        {
            // cout<<pick[i].first<<' '<<drop[j].first<<endl;
            if(pick[i].first<drop[j].first)
            {
                capacity-=pick[i].second;
                i++;
            }else if(pick[i].first>drop[j].first)
            {
                capacity+=drop[j].second;
                j++;
            }else
            {
                capacity+=drop[j].second;
                // capacity-=pick[i].second;
                // i++;
                j++;
            }
            // cout<<capacity<<endl;
            if(capacity<0)
            return false;
        }
        return true;
    }
};

// 1 2 , 5 3 
// 5 2 , 7 3

// 2 3,4 6,8 9
// 6 4,8 3,9 10