class Solution {
public:

    bool isSubsequence(string initialString, string s){
        int j = 0;

        for(int i=0; i<initialString.length() && j < s.length(); i++){
            if(initialString[i] == s[j])j++;
        }

        return j == s.length();
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        
        int totalCount = 0;

        map<string, int>subSeqFrequency;

        for(auto &w: words){
            subSeqFrequency[w]++;
        }

        for(auto &it:subSeqFrequency){
            if(isSubsequence(s, it.first))totalCount+=(it.second);
        }

        return totalCount;
    }
};
