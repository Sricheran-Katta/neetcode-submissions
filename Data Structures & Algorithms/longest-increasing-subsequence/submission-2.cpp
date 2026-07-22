class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, 0);
        // dp[0] = 1;
        // for (int i = 1; i < n; i++){
        //     for (int j = 0; j < i; j++){
        //         if(nums[j] < nums[i]){
        //             dp[i] = max(dp[i], 1 + dp[j]);
        //         }
        //         else{
        //             dp[i] = max(dp[i], 1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(), dp.end());
        vector<int> tails;
        for (int x : nums){
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()){
                tails.push_back(x);
            }
            else{
                *it = x;
            }
        }
        return tails.size();
    }
};
