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
    
    void addColumn(TreeNode* root, int val, int curDepth, int depth) {
        if(root == NULL) return;
        if(curDepth + 1 == depth) {
            root->left = new TreeNode(val, root->left, NULL);
            root->right = new TreeNode(val, NULL, root->right);
            return;
        }
        addColumn(root->left, val, curDepth+1, depth);
        addColumn(root->right, val, curDepth+1, depth);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) return new TreeNode(val, root, NULL);
        
        addColumn(root, val, 1, depth);
        
        return root;
    }
};
