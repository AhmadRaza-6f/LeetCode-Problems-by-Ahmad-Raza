class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, TreeNode*> mp;
        set<int> children;

        for (auto& d : des) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            TreeNode* p = mp[parent];
            TreeNode* c = mp[child];
            if (p == nullptr) {
                p = new TreeNode(parent);
                mp[parent] = p;
            }
            if (c == nullptr) {
                c = new TreeNode(child);
                mp[child] = c;
            }

            if (isLeft == 1) p->left = c; 
            else  p->right = c;

            children.insert(child);
        }
        for (auto& [val, node] : mp) {
            if (children.find(val) == children.end())
                return node;
        }
        return nullptr;
    }
};
