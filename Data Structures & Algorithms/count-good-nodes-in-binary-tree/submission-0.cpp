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
    int dfs(TreeNode* root , int pathGreatest){
        if(!root) return 0 ;

        int cnt = 0 ;

        if(root->val >= pathGreatest){
            cnt = 1;
            pathGreatest = root->val;
        }

        cnt += dfs(root->left , pathGreatest);
        cnt += dfs(root->right , pathGreatest);
        

        return cnt;
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root , root->val);
    }
};
