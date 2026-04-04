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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(key > root->val){
            root->right = deleteNode(root->right , key);
        }
        
        else if(key < root->val){
            root->left = deleteNode(root->left , key);
        }

        else{
            // node found ;

            if(!root->left) return root->right;
            if(!root->right) return root->left;

            auto rightSubtree = root->right;
            auto leftie = root->left;

            auto temp = rightSubtree;

            while(temp->left){
                temp = temp->left;
            }

            temp->left = leftie;

            return rightSubtree;
        }
        return root;
    }
};