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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
            return false;
        if(p->val!=q->val)
            return false;
        
        if(!isSameTree(p->left, q->left))
            return false;
        if(!isSameTree(p->right, q->right))
            return false;
        return true;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)
            return false;
        
        bool res=false;
        if(root->val==subRoot->val)
            res = isSameTree(root, subRoot);
        
        bool lRes = isSubtree(root->left, subRoot);
        bool rRes = isSubtree(root->right, subRoot);
        return (res || lRes || rRes);
    }
};
