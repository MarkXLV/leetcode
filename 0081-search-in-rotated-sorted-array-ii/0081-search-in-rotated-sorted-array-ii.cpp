

class Solution {
public :
    bool search(vector<int> nums, int target) {
        int start = 0; 
        int end = (int)nums.size() - 1;

        while (start <= end) {

            // to avoid duplicates
            while (start < end && nums[start] == nums[start + 1])
             ++start;
            while (start < end && nums[end] == nums[end - 1])
            --end;

            int mid = (end + start) / 2;
            cout<<mid<<start<<end<<endl;



            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] >= nums[start]) {

                if (target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;

            } else {

                if (target <= nums[end] && target > nums[mid])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};