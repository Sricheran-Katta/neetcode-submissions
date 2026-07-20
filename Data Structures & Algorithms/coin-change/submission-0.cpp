class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max_val = amount + 1;
        vector<int> dp(max_val, max_val);
        dp[0] = 0;
        for(int i = 1; i < max_val; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i >= coins[j]){
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        return dp[amount] == max_val ? -1 : dp[amount];
    }
};
