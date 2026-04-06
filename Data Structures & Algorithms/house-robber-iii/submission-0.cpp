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
    typedef long long ll;
private:
    pair<ll , ll> dfs(TreeNode* root){
        if(!root){
            return {0 , 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        auto withRoot = root->val + left.second + right.second;

        auto withOutRoot = max(left.first , left.second) + max(right.first , right.second);

        return {withRoot , withOutRoot};
    }
public:
    int rob(TreeNode* root) {
        if(!root) return 0 ;

        auto [first , second] = dfs(root);
        return max(first , second);
    }
};