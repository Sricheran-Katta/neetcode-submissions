class Solution {
private:
    void dfs(int index, vector<int>& nums, vector<int>& current_subset, vector<vector<int>>& result){
        if(index >= nums.size()){
            result.push_back(current_subset);
            return;
        }
        current_subset.push_back(nums[index]);
        dfs(index + 1, nums, current_subset, result);
        current_subset.pop_back();
        dfs(index + 1, nums, current_subset, result);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current_subset;
        dfs(0, nums, current_subset, result);
        return result;
    }
};
