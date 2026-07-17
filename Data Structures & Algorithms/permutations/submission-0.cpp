class Solution {
private:
    void dfs(int index, vector<bool>& verified, vector<int>& subarray, vector<int>& nums, vector<vector<int>>& results){
        if (subarray.size() == nums.size()){
            results.push_back(subarray);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            if( verified[i] == true){
                continue;
            }
            verified[i] = true;
            subarray.push_back(nums[i]);
            dfs(0, verified, subarray, nums, results);
            subarray.pop_back();
            verified[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> verified(nums.size(), false);
        int index = 0;
        vector<int> subarray;
        vector<vector<int>> results;
        dfs(index, verified, subarray, nums, results);
        return results;
    }
};
