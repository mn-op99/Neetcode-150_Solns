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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return vector<vector<int>>{};
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        vector<int> temp;
        vector<vector<int>> res;
        int row=1;

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int r = q.front().second;
            q.pop();
            if(row==r)
                temp.push_back(node->val);
            else{
                row++;
                res.push_back(temp);
                temp.clear();
                temp.push_back(node->val);
            }
            
            if(node->left!=NULL)
                q.push({node->left, r+1});
            if(node->right!=NULL)
                q.push({node->right, r+1});
        }
        res.push_back(temp);
        return res;
    }
};
