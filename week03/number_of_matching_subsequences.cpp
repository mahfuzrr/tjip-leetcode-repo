class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        int totalAns = 0;

        for(int i=0; i<words.size(); i++){
            int startingPos = 0;
            int isSubSequence = 0;

            for(int j=0; j<words[i].size(); j++){
                int index = s.find(words[i][j], startingPos);

                if(index >= 0){
                    startingPos = index+1;
                    isSubSequence = 1;
                }
                else{
                    isSubSequence = 0;
                     break;
                }
            }

            totalAns += isSubSequence;
        }

        return totalAns;
    }
};

/** using hashmap gives 29 - 35% faster runtime
    but this solution gives 95% faster runtime **/
