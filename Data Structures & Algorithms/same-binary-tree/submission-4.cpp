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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode* , TreeNode*>> pq;

        pq.push({p , q});

        while(!pq.empty()){
            auto [a , b] = pq.front();
            pq.pop();

            if(!a && !b) continue;

            if(!a || !b) return false;

            if(a->val != b->val) return false;

            pq.push({a->left , b->left});
            pq.push({a->right , b ->right});
            
        }
        return true;
    }
};
