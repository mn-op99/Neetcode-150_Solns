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
    bool heightBalanced=true;
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int leftH = solve(root->left);
        int rightH = solve(root->right);

        if(abs(leftH-rightH)>1)
            heightBalanced=false;
        
        return 1 + max(leftH, rightH);
    }
public:
    bool isBalanced(TreeNode* root) {
        int val = solve(root);
        return heightBalanced;
    }
};
