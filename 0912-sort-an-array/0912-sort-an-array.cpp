class Solution {
private:
    void countingSort(vector<int> &arr) {
        unordered_map<int, int> count;
        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());

        for (auto& val : arr) {
            count[val]++;
        }

        int index = 0;
        for (int val = minVal; val <= maxVal; ++val) {
            while (count[val] > 0) {
                arr[index] = val;
                index += 1;
                count[val] -= 1;
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        countingSort(nums);
        return nums;
    }
};