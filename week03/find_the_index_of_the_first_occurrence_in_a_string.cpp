class Solution {
public:
    int strStr(string haystack, string needle) {

        for(int i=0; i<haystack.length(); i++){
            if(haystack[i] == needle[0]){
                int j = 0;
                int startingIndex = i;

                while(j<needle.length() && i<haystack.length() && haystack[i] == needle[j]){
                    i++;
                    j++;
                }

                if(j >= needle.length())return startingIndex;
                i = startingIndex;

            }
        }

        return -1;
    }
};

/** This solution beats 100% runtime **/
