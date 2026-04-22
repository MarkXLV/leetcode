class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        map<int,int>mp;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>>usedRooms;
        priority_queue<long long, vector<long long>, greater<long long>> unusedRooms;
        for(int i=0;i<n;i++)
        {
            unusedRooms.push(i);
        }
        for(auto &interval:meetings)
        {
            int start=interval[0];
            int end=interval[1];
            // check how many used room finished their meetings and move them to unused rooms
            while(!usedRooms.empty() and usedRooms.top().first<=start)
            {
                int room=usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }
            if(!unusedRooms.empty())
            {
                int room=unusedRooms.top();
                unusedRooms.pop();
                mp[room]++;
                usedRooms.push({end,room});
            }else
            {
                auto [roomAvailabilityTime,room]=usedRooms.top();
                usedRooms.pop();
                mp[room]++;
                usedRooms.push({roomAvailabilityTime+end-start,room}); 
            }
            
        }

        int ans=0;
        int res=0;
        for(auto [room,freq]:mp)
        {
            if(freq>ans)
            {
                ans=freq;
                res=room;
            }
        }
        return res;
    }
};