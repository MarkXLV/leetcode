class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() < 2) return arr.size();
        int max_length = 1, current_length = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1]) {
                current_length = (i > 1 && arr[i - 1] < arr[i - 2]) ? current_length + 1 : 2;
            } else if (arr[i] < arr[i - 1]) {
                current_length = (i > 1 && arr[i - 1] > arr[i - 2]) ? current_length + 1 : 2;
            } else {
                current_length = 1;
            }
            max_length = max(max_length, current_length);
        }
        return max_length;
    }
};