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
    unordered_map<int, int> mpp_in;
    int preorder_idx = 0;

    TreeNode* build(const vector<int>& preorder, int int_start, int int_end){
        if (int_start > int_end){
            return nullptr;
        }
        int root_val = preorder[preorder_idx];
        TreeNode* root = new TreeNode(root_val);
        preorder_idx++;
        int split_idx = mpp_in[root_val];
        root->left = build(preorder, int_start, split_idx - 1);
        root->right = build(preorder, split_idx + 1, int_end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++){
            mpp_in[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};
