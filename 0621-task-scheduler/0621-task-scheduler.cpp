class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>mp;
        for(auto x:tasks)
        {
            mp[x-'A']++;
        }
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<26;i++)
        {
            if(mp[i]>0)
            {
                pq.push(mp[i]);
            }
        }

        int time=0;
  
        while(!pq.empty())
        {
            vector<int>reserve;
            int cycle=n+1;

            while(cycle and !pq.empty())
            {
                auto x=pq.top();
                pq.pop();
                if(x-1>0)
                {
                    reserve.push_back(x-1);
                }
                time++;
                cycle--;
            }

            for(auto count:reserve)
            pq.push(count);

            if(pq.empty())
            break;

            time+=cycle;
        }
        return time;
    }
};