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
    TreeNode *res = NULL;
    int solve(TreeNode* root, int p, int q){
        if(root==NULL)
            return -150;
        
        int l=solve(root->left, p, q);
        int r=solve(root->right, p, q);

        if((l==p && r==q) || (r==p && l==q)){
            res = root;
            return l;
        }
        else if((root->val==p && l==q) || (root->val==p && r==q) || (root->val==q && l==p) || (root->val==q && r==p)){
            res=root;
            return l;
        }
        else if(root->val==p)
            return p;
        else if(root->val==q)
            return q;

        if(l==p || l==q)
            return l;
        else if(r==p || r==q)
            return r;
        return -150;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = solve(root, p->val, q->val);
        return res;
    }
};
