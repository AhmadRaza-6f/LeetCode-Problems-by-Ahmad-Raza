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
void inorder(TreeNode* root,vector<int> &ans){
    if(!root)
        return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
TreeNode* solve(vector<int> &vec,int left , int right){
    if(left > right)
        return NULL;
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(vec[mid]);
    root->left = solve(vec,left,mid - 1);
    root->right = solve(vec,mid + 1, right);
    return root;
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> Inorder;
        inorder(root,Inorder);
        return solve(Inorder,0,Inorder.size() - 1);
    }
};
