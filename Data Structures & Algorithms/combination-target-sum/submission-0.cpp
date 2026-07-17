class Solution {
private:
    void dfs(int current_sum, int index, int target, vector<int>& nums, vector<int>& current_subset, vector<vector<int>>& result){
        if(index >= nums.size()){
            return;
        }
        if(current_sum > target){
            return;
        }
        if(current_sum == target){
            result.push_back(current_subset);
            return;
        }
        current_sum += nums[index];
        current_subset.push_back(nums[index]);
        dfs(current_sum, index, target, nums, current_subset, result);
        //dfs(current_sum, index + 1, target, nums, current_subset, result);
        current_sum -= nums[index];
        current_subset.pop_back();
        // dfs(current_sum, index, target, nums, current_subset, result);
        dfs(current_sum, index + 1, target, nums, current_subset, result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current_subset;
        int index = 0;
        int current_sum = 0;
        vector<vector<int>> result;
        dfs(current_sum, index, target, nums, current_subset, result);
        return result;
    }
};
