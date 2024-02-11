#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
// a helper function for sorting the vector of pair with respect to the second value
    static bool comparison(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    }

    vector<int> twoSum(vector<int>& nums, int target) {

       vector<pair<int,int>> numsWithIndex; // make a pair to store the nums value with index

        for(int i=0;i<nums.size();i++){
            numsWithIndex.push_back({i,nums[i]}); //initialize all value from nums to vector of pair
        }

        sort(numsWithIndex.begin(), numsWithIndex.end(), comparison); //sort the vector with respect to the second value

        vector<int> result;
        if(nums.size()==0) return result;//if the given nums vector is empty then it return empty vector
        int i=0,j=nums.size()-1;

        while(i<j){
            if(numsWithIndex[i].second+numsWithIndex[j].second<target) i++; //if the sum is less then the target then slide from left
            else if(numsWithIndex[i].second+numsWithIndex[j].second>target) j--;//if the sum is greater than the target then slide from right
            else{ //if sum is equal to the target then push it in result vector
                result.push_back(numsWithIndex[i].first);
                result.push_back(numsWithIndex[j].first);
                break;
            }
        }
        return result;
    }
};