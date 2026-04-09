class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day=0;
        map<long long,long long>allowed;
        int n=tasks.size();
        for(int i=0;i<n;i++)
        {
            day=max(day,allowed[tasks[i]]);
            day++;
            allowed[tasks[i]]=day+1ll*space;
            
        }
        return day;
    }
};