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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root){
            return root;
        }

        auto left = removeLeafNodes(root->left , target);
        auto right = removeLeafNodes(root->right , target);

        root->left = left ;
        root->right = right ;

        if(left == nullptr && right == nullptr && target == root->val){
            delete(root);
            return nullptr;
        }

        return root;
    }
};