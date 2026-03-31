class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
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
};
