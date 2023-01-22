// class Solution {
// public:
//     bool isPalindrome(string st){
//         int n = st.size();
//         int start =0, end=n-1;
//         while (start <= end)
//             if (st[start++] != st[end--])
//                 return false;

//         return true;
//     }
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> ans;
//         int n = s.size();
//         for(int i=0;i<n;i++){
//             vector<string> res;
//             for(int j=i;j<n;j++){
//                 string st = s.substr(i, j);
//                 if(isPalindrome(st)){
//                     res.push_back(st);
//                 }
//             }
//             ans.push_back(res);
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    bool isPalindrome(string &s, int start, int end)
    {
        while (start <= end)
            if (s[start++] != s[end--])
                return false;

        return true;
    }

    void dfs(int index, string &s, vector<string> &path, vector<vector<string>> &res)
    {
        if (index == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        if (s.empty())
            return res;

        vector<string> path;
        dfs(0, s, path, res);

        return res;
    }
};