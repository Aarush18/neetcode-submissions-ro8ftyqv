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
    void bfs(TreeNode* root , unordered_map<TreeNode* , TreeNode*>&parentMap){
            queue<TreeNode*> q;
            q.push(root);

            parentMap[root] = nullptr;

            while(!q.empty()){
                auto p = q.front();
                q.pop();

                if(p->left){
                    parentMap[p->left] = p;
                    q.push(p->left);
                }
                if(p->right){
                    parentMap[p->right] = p;
                    q.push(p->right);
                }
            }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->left== p && root->right == q) {
            return root ;
        }
        if(!root){
            return nullptr;
        }
        unordered_map<TreeNode*,TreeNode*> parentMap;
        bfs(root , parentMap);

        unordered_set<TreeNode*> ancestors;


        while(p){
            ancestors.insert(p);
            p = parentMap[p];
        }

        while(q){
            if(ancestors.count(q)){
                return q;
            }
            q = parentMap[q];
        }

        return root;

    }
};
