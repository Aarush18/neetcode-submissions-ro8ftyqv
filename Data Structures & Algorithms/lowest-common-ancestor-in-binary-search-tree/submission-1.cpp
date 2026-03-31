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
    void bfs(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& parentMap){
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if(node->left){
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*>parentMap;
        if(!root) return root;
        if(root->left == p && root->right ==q){
            return root;
        }

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
