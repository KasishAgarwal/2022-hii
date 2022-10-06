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
    
    void checkSum(TreeNode* root, int currSum, int targetSum, bool &ans) {
        
        currSum += root->val;

        if(root->left == NULL && root->right == NULL) {
            if(targetSum == currSum) ans = true;
            return;
        }
        
        if(root->left != NULL) checkSum(root->left, currSum, targetSum, ans);
        if(root->right != NULL) checkSum(root->right, currSum, targetSum, ans);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        
        if(root == NULL) return false;
        
        checkSum(root, 0, targetSum, ans);
        
        return ans;
        
    }
};
