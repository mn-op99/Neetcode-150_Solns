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
public:
    int kthSmallest(TreeNode* root, int &k) {
        int l=INT_MIN, r=INT_MIN;
        if(root->left!=NULL){
            l = kthSmallest(root->left, k);
        }
        k--;
        if(k==0)
            return root->val;
        if(root->right!=NULL){
            r = kthSmallest(root->right, k);
        }

        return l!=INT_MIN?l:r;
    }
};
