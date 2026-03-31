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
        queue< pair<TreeNode* , TreeNode* >> qu;

        qu.push({p , q});

        while(!qu.empty()){
            
            int size = qu.size();

            for(int i = 0 ; i < size ; i++){
                auto t = qu.front();
                qu.pop();


                if(!t.first && !t.second) continue;
                if(!t.first || !t.second) return false;

                if((t.first->left && !t.second->left) ||
                   (!t.first->left && t.second->left))
                    return false;

                if((t.first->right && !t.second->right) ||
                   (!t.first->right && t.second->right))
                    return false;

                if(t.first->val != t.second->val){
                    return false;
                }
                if(t.first->left && t.second->left){
                    qu.push({t.first->left , t.second->left});
                }
                if(t.first->right && t.second->right){
                    qu.push({t.first->right , t.second->right});
                }
            }
        }
        return true;
    }
};
