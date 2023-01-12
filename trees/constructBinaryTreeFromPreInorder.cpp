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
    TreeNode *buildTreeHelper(vector<int> inOrder, vector<int> preOrder, int inS, int inE, int preS, int preE)
    {
        if (inS > inE)
            return NULL;

        int rootData = preOrder[preS];
        int rootIndex = -1;
        for (int i = inS; i <= inE; i++)
            if (inOrder[i] == rootData)
            {
                rootIndex = i;
                break;
            }

        int leftInS = inS;                           // 0
        int leftInE = rootIndex - 1;                 // 1-1=0
        int leftPreS = preS + 1;                     // 1
        int leftPreE = leftPreS + leftInE - leftInS; // 1+0-0=1

        int rightInS = rootIndex + 1; // 2
        int rightInE = inE;           // 4
        int rightPreS = leftPreE + 1; // 1+1=2
        int rightPreE = preE;         // 4

        TreeNode *root = new TreeNode(rootData);
        root->left = buildTreeHelper(inOrder, preOrder, leftInS, leftInE, leftPreS, leftPreE);
        root->right = buildTreeHelper(inOrder, preOrder, rightInS, rightInE, rightPreS, rightPreE);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        return buildTreeHelper(inorder, preorder, 0, n - 1, 0, n - 1);
    }
};