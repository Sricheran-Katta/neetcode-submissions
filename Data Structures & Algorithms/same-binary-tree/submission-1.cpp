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
    bool indicator = true;
    void dfs(TreeNode* p, TreeNode* q){
        if (p == nullptr && q == nullptr)return;
        else if (p != nullptr && q != nullptr) {
            indicator = indicator && (p->val == q->val);
            dfs(p->left, q->left);
            dfs(p->right, q->right);
        }
        else {
            indicator = false;
            return;
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        indicator = true;
        dfs(p, q);
        return indicator;
    }
};
