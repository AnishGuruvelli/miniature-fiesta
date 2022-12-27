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

class Solution
{
public:
    void helper(TreeNode *root, int &minD, int &height)
    {
        if (!root)
            return;
        
        ++height;

        if (!root->left && !root->right)
            minD = min(minD, height);

        helper(root->left, minD, height);
        helper(root->right, minD, height);
        
        --height;
    }
    
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        
        int minD = INT_MAX;
        int height = 0;
        
        helper(root, minD, height);
        
        return minD;
    }
};
