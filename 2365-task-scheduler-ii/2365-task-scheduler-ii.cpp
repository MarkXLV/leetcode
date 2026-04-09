class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> last_time;
        long long day = 0;

        for (int task : tasks) {
            if (last_time.count(task)) {
                day = max(day, last_time[task] + space + 1);
            }
            last_time[task] = day;
            day++;
        }

        return day;
    }
};