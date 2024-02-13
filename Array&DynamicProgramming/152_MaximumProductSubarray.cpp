class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct=INT_MIN;
        int leftProduct=1;
        int rightProduct=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(leftProduct==0) leftProduct=1;
            if(rightProduct==0) rightProduct=1;

            leftProduct*=nums[i];
            rightProduct*=nums[n-i-1];
            maxProduct=max(maxProduct,max(leftProduct,rightProduct));
        }
        return maxProduct;
    }
};