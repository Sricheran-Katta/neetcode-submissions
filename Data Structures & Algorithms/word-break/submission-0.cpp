class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < i; j++){
                if (dp[j] == true){
                    if(st.find(s.substr(j, i - j)) != st.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
