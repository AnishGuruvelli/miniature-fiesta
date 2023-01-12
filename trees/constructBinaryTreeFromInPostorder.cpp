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
    TreeNode *buildTreeHelper(vector<int> inOrder, vector<int> postOrder, int inS, int inE, int poS, int poE)
    {
        if (inS > inE)
            return NULL;

        int rootData = postOrder[poE];
        int rootIndex = -1;
        for (int i = inS; i <= inE; i++)
            if (inOrder[i] == rootData)
            {
                rootIndex = i;
                break;
            }

        int leftInS = inS;
        int leftInE = rootIndex - 1;
        int leftPoS = poS;
        int leftPoE = leftPoS + leftInE - leftInS;

        int rightInS = rootIndex + 1;
        int rightInE = inE;
        int rightPoS = leftPoE + 1;
        int rightPoE = poE - 1;

        TreeNode *root = new TreeNode(rootData);
        root->left = buildTreeHelper(inOrder, postOrder, leftInS, leftInE, leftPoS, leftPoE);
        root->right = buildTreeHelper(inOrder, postOrder, rightInS, rightInE, rightPoS, rightPoE);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        return buildTreeHelper(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};