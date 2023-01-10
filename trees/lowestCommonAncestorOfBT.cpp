/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    // TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    // {
    //     if (!root || root == p || root == q)
    //         return root;

    //     TreeNode *left = lowestCommonAncestor(root->left, p, q);
    //     TreeNode *right = lowestCommonAncestor(root->right, p, q);

    //     if (!left)
    //         return right;

    //     if (!right)
    //         return left;

    //     return root;
    // }

    TreeNode *dfsTraverse(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q || root == NULL)
            return root;

        TreeNode *parent1 = dfsTraverse(root->left, p, q);
        TreeNode *parent2 = dfsTraverse(root->right, p, q);

        if (parent1 && parent2)
            return root;
        else
            return parent1 ? parent1 : parent2;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return dfsTraverse(root, p, q);
    }
};

