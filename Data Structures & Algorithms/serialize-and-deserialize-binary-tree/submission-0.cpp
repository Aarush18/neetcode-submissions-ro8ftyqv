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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        queue<TreeNode*> q;
        q.push(root);

        string ans = "";   

        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                auto p = q.front();
                q.pop();

                if(!p){
                    ans+="#,";
                    continue;
                }
                ans+=to_string(p->val) + ",";

                q.push(p->left);
                q.push(p->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return nullptr;
       if(data.size() == 0) return nullptr;
       stringstream s(data);

       string str;

       getline(s , str , ',');

       TreeNode* root = new TreeNode(stoi(str));

       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){
          TreeNode * node = q.front();
          q.pop();

          getline(s ,str , ',');

          if(str == "#"){
            node->left = nullptr;
          }else{
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
          }

          getline(s , str ,',');
          if(str == "#"){
            node->right = nullptr;
          }else {
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
          }
       }
       return root;
    }
};
