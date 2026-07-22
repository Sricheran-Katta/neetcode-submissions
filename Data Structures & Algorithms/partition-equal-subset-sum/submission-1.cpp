class Solution {
    bool solve(vector<int>& nums, int index, int target, vector<vector<int>>& memo){
        if( target == 0) return true;
        if(target < 0 || index < 0) return false;
        if(memo[index][target] != -1){
            return memo[index][target];
        }
        bool skip = solve(nums, index - 1, target, memo);
        bool include = false;
        if( target >= nums[index]){
            include = solve(nums, index - 1, target - nums[index], memo);
        }
        return memo[index][target] = (skip||include);
    }
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i : nums){
            totalSum += i;
        }
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int> (target + 1, -1));
        return solve(nums, n - 1, target, memo);
    }
};
