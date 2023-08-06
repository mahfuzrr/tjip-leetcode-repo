class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>>track;

        track.push({"", 1});
        int times = 0;

        for(auto &ch: s){
            if(isdigit(ch)){
                times = (times * 10) + (ch - '0');
            }
            else if(ch == '['){
                track.push({"", times});
                times = 0;
            }
            else if(ch == ']'){
                string str = track.top().first;
                int freq = track.top().second;
                track.pop();

                while(freq--){
                    track.top().first += str;
                }
            }
            else{
                track.top().first.push_back(ch);
            }
        }

        return track.top().first;
    }
};
