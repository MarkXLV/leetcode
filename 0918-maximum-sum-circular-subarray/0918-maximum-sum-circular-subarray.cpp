class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_kadane = kadane(nums);
        int total_sum = 0;
        for (int num : nums) total_sum += num;
        for (int& num : nums) num = -num;
        int min_kadane = kadane(nums);
        int circular_max = total_sum + min_kadane;
        if (circular_max == 0) return max_kadane;
        return max(max_kadane, circular_max);
    }
    
private:
    int kadane(vector<int>& arr) {
        int current_max = arr[0], global_max = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            current_max = max(arr[i], current_max + arr[i]);
            global_max = max(global_max, current_max);
        }
        return global_max;
    }
};