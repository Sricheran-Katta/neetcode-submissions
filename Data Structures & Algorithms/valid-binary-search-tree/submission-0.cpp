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
    bool dfsvalid(TreeNode* node, int min_val, int max_val){
        if (node == nullptr) return true;
        if (node->val <= min_val || node->val >= max_val){
            return false;
        }
        bool leftisvalid = dfsvalid(node->left, min_val, node->val);
        bool rightisvalid = dfsvalid(node->right, node->val, max_val);
        return leftisvalid && rightisvalid;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfsvalid(root, INT_MIN, INT_MAX);
    }
};
