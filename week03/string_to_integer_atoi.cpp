class Solution {
public:
    int myAtoi(string s) {
        char sign = '+';
        int i = 0;

        while(i<s.length() && s[i] == ' ')i++;

        if(s[i] == '-'){
            sign = '-';
            i++;
        }
        else if(s[i] == '+')i++;

        long long int ans = 0;


        while(i<s.length() && s[i] >= 48 && s[i] <= 57){
            if(ans > INT_MAX){
               if(sign == '-')return INT_MIN;
               return INT_MAX;
            }
            
            ans *= 10;
            ans += (s[i] - 48);
            i++;
        }

        if(sign == '-'){
            ans*=(-1);
            if(ans < -2147483647)ans = -2147483648;
        }
        if(ans > INT_MAX)ans = INT_MAX;

        return (int) ans;
    }
};
