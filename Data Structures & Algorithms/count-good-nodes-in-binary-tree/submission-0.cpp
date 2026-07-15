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
    int dfsgood(TreeNode* root, int max_so_far){
        if (root == nullptr){
            return 0;
        }
        int good = 0;
        if (root->val >= max_so_far){
            good = 1;
        }
        int new_max = max(max_so_far, root->val);
        int good_left = dfsgood(root->left, new_max);
        int good_right = dfsgood(root->right, new_max);
        return good_left + good + good_right;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfsgood(root, root->val);
    }
};
