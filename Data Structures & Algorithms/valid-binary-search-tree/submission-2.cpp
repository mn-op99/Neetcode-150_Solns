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
    int currVal=INT_MIN;
    bool res=true;
    void solve(TreeNode* root){
        if(root==NULL)
            return;
        
        isValidBST(root->left);
        if(root->val > currVal)
            currVal = root->val;
        else
            res=false;
        isValidBST(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        solve(root);
        return res;
    }
};
