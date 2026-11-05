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
    int maxVal=INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        if(l+r+root->val > maxVal){
            maxVal = l+r+root->val;
        }

        if((l+root->val)<0 && (r+root->val)<0)
            return 0;
        return max(l+root->val, r+root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxVal;
    }
};
