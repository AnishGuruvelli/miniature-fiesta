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

// class Solution
// {
// public:
//     int kthSmallest(TreeNode *root, int k)
//     {
//         if (!root)
//             return 0;

//         vector<int> v;
//         queue<TreeNode *> q;
//         q.push(root);

//         while (!q.empty())
//         {
//             root = q.front();
//             q.pop();
//             v.push_back(root->val);

//             if (root->left)
//                 q.push(root->left);
//             if (root->right)
//                 q.push(root->right);
//         }

//         sort(v.begin(), v.end());

//         if (v.size() < k)
//             return 0;

//         return v[k - 1];
//     }
// };

class Solution
{
public:
    priority_queue<int, vector<int>, greater<int>> p;
    void inorder(TreeNode *Node)
    {
        if (!Node)
            return;
        inorder(Node->left);
        p.push(Node->val);
        inorder(Node->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root);
        int j;
        for (int i = 1; i < k; ++i)
        {
            p.pop();
        }
        return p.top();
    }
};
