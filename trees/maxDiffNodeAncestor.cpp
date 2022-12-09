// MADD QUESTION: TRY TO SOLVE IT ON OWN, FUCKING TOO GOOD

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
    int maxAncestorDiff(TreeNode *root, int mn = 100000, int mx = 0)
    {
        if (root == nullptr)
            return mx - mn;

        mx = max(mx, root->val);
        mn = min(mn, root->val);

        return max(maxAncestorDiff(root->left, mn, mx), maxAncestorDiff(root->right, mn, mx));
    }
};