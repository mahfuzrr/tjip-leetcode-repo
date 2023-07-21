class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char>longestSubstr;

        vector<int>frequency(255, 0);

        int finalAns = 0;

        for(int i=0; i<s.length(); i++){
            if(frequency[s[i] - 0]){
                finalAns = max(finalAns, (int)longestSubstr.size());

                while(longestSubstr.front() != s[i]){
                    frequency[longestSubstr.front() - 0]--;
                    longestSubstr.pop();
                }

                frequency[longestSubstr.front() - 0]--;
                longestSubstr.pop();
                longestSubstr.push(s[i]);
                frequency[s[i] - 0]++;
            }
            else{
                longestSubstr.push(s[i]);
                frequency[s[i] - 0]++;
            }
        }

        return max(finalAns, (int)longestSubstr.size());
    }
};
