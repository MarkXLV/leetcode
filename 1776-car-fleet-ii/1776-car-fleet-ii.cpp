class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> answer(n, -1);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            int position_i = cars[i][0];
            int speed_i = cars[i][1];
            while (!s.empty()) {
                int j = s.top();
                int position_j = cars[j][0];
                int speed_j = cars[j][1];
                if (speed_i <= speed_j) {
                    s.pop();
                } else {
                    double collision_time = (double)(position_j - position_i) / (speed_i - speed_j);
                    if (answer[j] == -1 || collision_time <= answer[j]) {
                        answer[i]=collision_time;
                        break;
                    } else {
                        s.pop();
                    }
                }
            }
            s.push(i);
        }
        return answer;
    }
};