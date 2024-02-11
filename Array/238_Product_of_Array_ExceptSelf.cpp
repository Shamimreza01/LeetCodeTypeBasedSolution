class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int leftCurrentProduct=1; // initialize left current product 1
        vector<int> leftProductContainer; //declear a container to contain the left side product except itself
        leftProductContainer.push_back(1);  // and initialize it firstly 1;

        for(int i=1;i<nums.size();i++){ //now from the index 1 because at index zero the product except itself is 1
            leftCurrentProduct*=nums[i-1]; //left current product except itself at index i
            leftProductContainer.push_back(leftCurrentProduct);   //and push it at ith index 
        }

        int rightCurrentProduct=1;    //initialize right current product is 1
        vector<int> rightProductContainer;  // container to contain right current product 
        rightProductContainer.push_back(1);   // initial it 1 because 1st product except itself is one

        for(int j=nums.size()-2;j>=0;j--){
            rightCurrentProduct*=nums[j+1];
            rightProductContainer.push_back(rightCurrentProduct);
        }

        vector<int> result;

        int j=rightProductContainer.size()-1;
        for(int i=0;i<nums.size();i++,j--){  //at index i the product of leftside product Except itself and rightSide product Except itself is the product total array except itself
            result.push_back(leftProductContainer[i]*rightProductContainer[j]);
        }
        return result;
    }
};
/* explanation
                       1   2   3  4 
leftcurrentProduct     1   1   2  6
rightcurrentProduct    24  12  4  1
result                 24  13  8  6

*/
