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
    int solve(TreeNode* root, int maxVal){
        if(root==NULL)
            return 0;
        
        int l = solve(root->left, max(maxVal, root->val));
        int r = solve(root->right, max(maxVal, root->val));

        if(root->val >= maxVal)
            return 1 + l + r;
        return l + r;
    }
public:
    int goodNodes(TreeNode* root) {
        int maxVal = -150;
        return solve(root, maxVal);
    }
};
