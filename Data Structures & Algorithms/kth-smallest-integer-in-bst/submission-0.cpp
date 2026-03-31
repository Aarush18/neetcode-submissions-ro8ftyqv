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
    int ans = -1;
    int cnt =  0;

    void dfs(TreeNode* root , int k ){
        if(ans != -1 || !root) return;

        dfs(root->left , k);
        cnt++;
        if(cnt == k){
            ans = root->val;
        }
        dfs(root->right , k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0 ; 
        if(k == 0 ) return 0 ;

        dfs(root , k);

        return ans;
    }
};
