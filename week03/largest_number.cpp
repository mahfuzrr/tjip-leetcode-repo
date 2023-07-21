class Solution {
public:
    static bool isLess(int &firstNumber, int &secondNumber){
        string firstString = to_string(firstNumber);
        string secondString = to_string(secondNumber);
        
        return firstString+secondString > secondString+firstString;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), isLess);

        if(nums[0] == 0)return "0";

        string finalAnswer = "";
        for(auto &it:nums){
            finalAnswer += to_string(it);
        }

        return finalAnswer;
    }
};
