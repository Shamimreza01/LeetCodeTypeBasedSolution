class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target)
                return true;
                
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                // if left=mid=right then three are same so
                // it is dublicated . and we cannot take
                // decission that which one is sorted
                left++;
                right--;
                continue;
            }
            if (nums[mid] < nums[left]) { // so the left half is not sorted. the
                                          // right half is sorted
                if (nums[mid] <= target &&
                    target <= nums[right]) // if target is in right part
                    left = mid + 1;
                else
                    right = mid - 1; // the target is in left part
            } else {                 // if left half is sorted .
                if (nums[left] <= target &&
                    target <= nums[mid]) // if target is in left half
                    right = mid - 1;
                else
                    left = mid + 1; // target is in right half
            }
        }
        return false;
    }
};