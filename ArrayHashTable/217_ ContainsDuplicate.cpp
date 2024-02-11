//solution one

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool isDuplicate=false; //initiali there is duplicate 
         //take a unordered map to store the nums value and the number of occurrence
       unordered_map<int,int> numsWithOccar; //we use unordered map because unordered map have time complexity is less than map
        for(auto num:nums){
            numsWithOccar[num]++; //if one occur again then it increase value
        }
        for(auto num:numsWithOccar){
            if(num.second>1) { 
                isDuplicate=true;
                break;
            }
        }
        return isDuplicate;
    }
};

//we can use another solution
//solution two
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
          sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};
*/