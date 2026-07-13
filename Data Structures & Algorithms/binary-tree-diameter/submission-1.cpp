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
    int max_diameter = 0;
    int dfsheight(TreeNode* root){
        if (root == nullptr){return 0;}
        int leftheight = dfsheight(root->left);
        int rightheight = dfsheight(root->right);
        max_diameter = max(max_diameter, leftheight + rightheight);
        return 1 + max(leftheight, rightheight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfsheight(root);
        return max_diameter;
    }
};
