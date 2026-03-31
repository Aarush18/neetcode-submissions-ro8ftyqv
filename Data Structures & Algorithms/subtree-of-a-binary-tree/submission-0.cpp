class Solution {
private:
    bool isSame(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push({p, q});

        while (!qu.empty()) {
            auto [a, b] = qu.front();
            qu.pop();

            if (!a && !b) continue;
            if (!a || !b) return false;
            if (a->val != b->val) return false;

            qu.push({a->left, b->left});
            qu.push({a->right, b->right});
        }
        return true;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur->val == subRoot->val && isSame(cur, subRoot))
                return true;

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return false;
    }
};
