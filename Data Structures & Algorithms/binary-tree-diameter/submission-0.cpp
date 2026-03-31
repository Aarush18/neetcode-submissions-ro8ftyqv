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
    int dia = 0 ;
private: 
    int dfs(TreeNode* node){
        if(!node) return 0;

        int lh = dfs(node -> left);
        int rh = dfs(node -> right);

        dia = max(dia , lh + rh);

        return 1 + max(lh , rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        dfs(root);
        return dia;

    } 
};
