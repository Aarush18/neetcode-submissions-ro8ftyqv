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
    int maxSum = INT_MIN ;
private:
    int calcSum(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int lsum = max(0 , calcSum(root->left));
        int rsum = max(0 , calcSum(root->right));

        maxSum = max(maxSum , lsum + rsum + root->val);

        return root->val + max(lsum , rsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        calcSum(root);
        return maxSum;
    }
};
