class Solution {
    void traverse(TreeNode* root, int num, int& val) {
        if (!root) return;
        
        num = (num << 1) | root->val;  // shift left and add current bit
        
        if (!root->left && !root->right) {
            val += num;
            return;
        }
        
        traverse(root->left, num, val);
        traverse(root->right, num, val);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        traverse(root, 0, ans);
        return ans;
    }
};
