// class Solution
// {
// public:
// THIS CODE IS FOR PRINTING THIS : abc ab ac a bc b c

// vector<string> ans;
// void solve(int i, string s, string &temp, int n){
//     if(i==n)
//     {
//         ans.push_back(temp);
//         return;
//     }

//     temp += s[i];
//     solve(i+1, s, temp, n);
//     temp.pop_back();
//     solve(i+1, s, temp, n);
// }
// vector<int> findAnagrams(string s, string p) {
//     string temp = "";
//     solve(0, p, temp, p.size());
//     for(auto i: ans) cout<<i<<" ";
//     return {};
// }

// };

// SLIDING WINDOW METHOD

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        int n = s.length(), m = p.length();

        if (m > n)
            return {};

        vector<int> pv(26, 0), sv(26, 0), res;

        for (int l = 0; l < m; l++)
            pv[p[l] - 'a']++;

        int i = 0, j = 0;

        while (j < n)
        {
            sv[s[j] - 'a']++;

            // When the current window size is smaller, just move ahead.
            if ((j - i + 1) < m)
                j++;

            // On hitting the window.
            else if ((j - i + 1) == m)
            {
                if (pv == sv)
                    res.push_back(i);

                sv[s[i] - 'a']--;

                i++;
                j++;
            }
        }
        return res;
    }
};