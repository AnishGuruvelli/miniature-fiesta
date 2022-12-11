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

// DO THIS QUESTION BEFORE AND THEN SOLVE THIS: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
// MADNESS

class Solution
{
public:
    int subTreesum(TreeNode *root, int &mx)
    {
        if (root == NULL)
            return 0;

        // we are using max function over here because as we know node can be negative ,
        // and we also know that when we take negative nodes
        // then they will reduce our path cost but we need to maximize it as much as possible
        // so whenever we get negative nodes then just take 0 instead of negative value
        int l = max(0, subTreesum(root->left, mx));
        int r = max(0, subTreesum(root->right, mx));

        int curr = root->val + l + r;
        // curr node + left node + right node (path sum for curr node)

        cout << curr << " ";

        mx = max(mx, curr);
        // took max out of all

        return root->val + max(l, r);
        // max(l,r) means we will chose one path that will gave max path sum to us
    }
    int maxPathSum(TreeNode *root)
    {
        int mx = INT_MIN;
        subTreesum(root, mx);
        return mx;
    }
};

// THIS APPROACH DOESNT WORK CUZ WHEN ROOT IS 200 AND THEN ITS LEAD NODE IS -100, THEN VECTOR WILL STORE, -100 AND 100; AND NOT 200 ALONE, WHEREAS ANSWER SHOULD BE 200

// class Solution
// {
// public:
//     vector<int> ans;
//     int dfs(TreeNode *root)
//     {
//         if (!root)
//             return 0;

//         int res = dfs(root->left) + root->val + dfs(root->right);
//         ans.push_back(res);
//         // for first test case: vector will be 2,3,6
//         // for second test case: vector will be 9,15,7,42,41

//         return res;
//     }
//     int maxPathSum(TreeNode *root)
//     {
//         dfs(root);
//         sort(ans.begin(), ans.end());
//         int n = ans.size();
//         return ans[n - 1];
//     }
// };
