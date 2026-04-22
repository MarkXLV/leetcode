class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
        std::set<long> window; // Use long to prevent overflow in abs calculation
        for (int i = 0; i < nums.size(); ++i) {
            // Maintain the window size
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }
            
            // Find the smallest number greater than or equal to nums[i] - valueDiff
            auto pos = window.lower_bound((long)nums[i] - valueDiff);
            
            // Check if this number is within valueDiff of nums[i]
            if (pos != window.end() && std::abs(*pos - nums[i]) <= valueDiff) {
                return true;
            }
            
            // Insert current number into the set
            window.insert(nums[i]);
        }
        return false;
    }
};