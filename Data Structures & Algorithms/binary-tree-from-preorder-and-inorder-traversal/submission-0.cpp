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
    TreeNode* solve(vector<int>& preorder, int lp, int rp, vector<int>& inorder, int li, int ri, unordered_map<int, int> &mp){
        if(lp>rp)
            return NULL;
        TreeNode* node = new TreeNode(preorder[lp]);

        int idx = mp[preorder[lp]];

        int leftNumEle = idx - li;
        int rightNumEle = ri - idx;

        TreeNode* lCall = solve(preorder, lp+1, lp + leftNumEle, inorder, li, idx-1, mp);
        TreeNode* rCall = solve(preorder, lp+leftNumEle+1, rp, inorder, idx+1, ri, mp);

        node->left = lCall;
        node->right = rCall;
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; ++i){
            mp[inorder[i]]=i;
        }

        return solve(preorder, 0, n-1, inorder, 0, n-1, mp);
    }
};
