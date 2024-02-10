#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
   void Helper(string digits,int index,string output,vector<string> &combinations,vector<string> buttons){
       if(index>=digits.length()){
           combinations.push_back(output); //when the index is greater than the length of the given number string
           return ;
       }
       int digit=digits[index]-'0'; // to get the digit from the digits string
       string button=buttons[digit]; //to get the string for the current digit

       for(auto s:button){ //get each character from the current digit string and add it to the output string
           output.push_back(s); 
           Helper(digits,index+1,output,combinations,buttons); //and then go to the next index and do the same task
           output.pop_back();
       }
   }
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if(digits.length()==0) return combinations;
        vector<string> buttons={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        string output;

        Helper(digits, index,output,combinations,buttons);
        
        return combinations;
        
    }
};