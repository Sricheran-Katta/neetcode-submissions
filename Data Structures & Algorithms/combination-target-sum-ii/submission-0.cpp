class Solution {
private:
    void dfs(int index, int target, vector<int>& candidates, vector<int>& current_subset, vector<vector<int>>& result){
        if (target == 0){
            result.push_back(current_subset);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            if (candidates[i] > target){
                break;
            }
            if (i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            current_subset.push_back(candidates[i]);
            dfs(i+1, target - candidates[i], candidates, current_subset, result);
            current_subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int index = 0;
        int current_sum = 0;
        vector<int> current_subset;
        vector<vector<int>> result;
        dfs(0, target, candidates, current_subset, result);
        return result;
    }
};
