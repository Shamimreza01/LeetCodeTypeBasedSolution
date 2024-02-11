class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0]; //initial maxSum with the 1st value 
        int currSum=nums[0];
        for(int i=1;i<nums.size();i++){
            currSum=max(nums[i],currSum+nums[i]); //if after the adding the currentSum with the latest value is less than the current sum then it means that current sum is less than zero so neglect it 
            maxSum=max(maxSum,currSum); // everytime it update maximum value
        }
        return maxSum;
    }
};