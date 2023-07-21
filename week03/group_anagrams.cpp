class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>>anagramMap;

        for(auto &it:strs){
            string temp = it;
            sort(temp.begin(), temp.end());
            anagramMap[temp].push_back(it);
        }

        vector<vector<string>>finalAnswer;

        for(auto it:anagramMap){
            finalAnswer.push_back(it.second);
        }

        return finalAnswer;
    }
};
