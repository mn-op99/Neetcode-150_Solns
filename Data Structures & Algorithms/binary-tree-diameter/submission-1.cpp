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
    int maxVal=1;
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;

        int leftDepth = solve(root->left);
        int rightDepth = solve(root->right);
        
        maxVal = max(maxVal, 1 + leftDepth + rightDepth);
        
        return 1 + max(leftDepth, rightDepth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int val = solve(root);
        return maxVal-1;
    }
};
