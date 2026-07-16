/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int max_sum = INT_MIN;
    int dfs(TreeNode* root){
        if (root == nullptr){return 0;}
        int leftsum = max(0, dfs(root->left));
        int rightsum = max(0, dfs(root->right));
        max_sum = max(max_sum, leftsum + rightsum + root->val);
        return root->val + max(leftsum, rightsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};
