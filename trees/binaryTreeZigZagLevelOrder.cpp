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

// not working for some reason

// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         if(!root) return ans;
//         int count=1;
//         while(!q.empty()){
//             vector<int> level;
//             int len = q.size();
//             for(int i=0;i<len;i++){
//                 TreeNode* node = q.front();
//                 q.pop();
//                 if(count%2==0){
//                     if(node->left) q.push(node->left);
//                     if(node->right) q.push(node->right);
//                 }
//                 else{
//                     if(node->right) q.push(node->right);
//                     if(node->left) q.push(node->left);
//                 }
//                 level.push_back(node->val);
//                 count++;
//             }
//             ans.push_back(level);
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        int i = 0;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> v;
            while (sz--)
            {
                TreeNode *f = q.front();
                v.push_back(q.front()->val);
                q.pop();
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
            if (i++ % 2)
                reverse(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
};

// vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//     vector<vector<int>>ans;
//     if(!root)return ans;
//     queue<TreeNode*>q;
//     q.push(root);
//     int i=0;
//     while(!q.empty()){
//        int sz=q.size();
//        vector<int>v(sz);
//        int j=0,n=sz;
//        while(sz--){
//            TreeNode * f=q.front();
//            q.pop();
//            if(i%2==0)
//            v[j]=f->val;
//            else v[n-j-1]=f->val;
//            j++;
//            if(f->left)q.push(f->left);
//            if(f->right)q.push(f->right);
//        }
//        i++;
//        ans.push_back(v);

//     }
//     return ans;

// }