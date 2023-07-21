class Solution {
public:
    bool isValid(string s) {
        stack<char>parentheses;

        map<char, char>isPair;
        isPair = {{')', '('}, {'}', '{'}, {']', '['}};

        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                parentheses.push(s[i]);
            }
            else{

                if(parentheses.empty())return false;
                if(isPair[s[i]] == parentheses.top()){
                    parentheses.pop();
                }
                else return false;
            }
        }

        return parentheses.empty();
    }
};
