class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0 || s[0] == '0') return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i < n + 1; i++){
            if ('1' <= s[i - 1] && s[i - 1] <= '9'){
                dp[i] += dp[i-1];
            }
            int twodigits = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (10 <= twodigits && twodigits <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
