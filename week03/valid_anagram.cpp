class Solution {
public:

    void countingSort(string &s){
        vector<int>frequency(26, 0);

        for(auto it:s){
            frequency[it - 97]++;
        }

        int j = 0;

        for(int i=0; i<26; i++){
            while(frequency[i]--){
                s[j] = 'a' + i;
                j++;
            }
        }
    }

    bool isAnagram(string s, string t) {
        countingSort(s);
        countingSort(t);

        return s==t;
    }
};
