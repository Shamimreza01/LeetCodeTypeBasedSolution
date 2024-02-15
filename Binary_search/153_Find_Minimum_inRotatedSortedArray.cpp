class Solution {
public:
    int findMin(vector<int>& nums) {
        int minNum;
        int n = nums.size();
        int left = 0, right = n - 1;
        int result=INT_MAX;
        while (left <=right) {
            int mid = (left + right) / 2;
            
            if(nums[left]<=nums[mid]){ //if left part is sorted then take the minimum from left part and remove this 
                    result=min(result,nums[left]);  // and the minumum is nums left 
                    left=mid+1;
            }else{ //if right part is sorted then the minimum is nums[mid]
                result=min(result,nums[mid]);
                right=mid-1;
            }
        }
        return result;
    }
};