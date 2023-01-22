// O(N) TIME COMPLEXITY

// class Solution {
// public:
//     string removeStars(string s) {
//         string ans;
//         for(char c:s){
//             if(c=='*' && !ans.empty())ans.pop_back();
//             else if(c!='*')ans.push_back(c);
//         }
//         return ans;
//     }
// };


// THIS WILL GIVE TLE

// class Solution
// {
// public:
//     string removeStars(string s)
//     {
//         stack<char> st;
//         for (char i : s)
//         {
//             if (i == '*')
//                 st.pop();
//             else
//                 st.push(i);
//         }

//         s = "";
//         while (!st.empty())
//         {
//             s = st.top() + s;
//             st.pop();
//         }

//         return s;
//     }
// };

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;
        for (char i : s)
        {
            if (i == '*')
                st.pop();
            else if(i >= 'a' && i <= 'z' || i >= '0' && i <= '9' || i >= 'A' && i <= 'Z')
                st.push(i);
        }

        string ans = "";
        while(!st.empty())
        {
            char res = st.top();
            st.pop();
            ans.push_back(res);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// class Solution {
// public:
//     string removeStars(string s) {
//         int n = s.length();
//         stack<char>sp;
//         string ans = "";
//         for(int i = 0; i < n; i++)
//         {
//             if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'Z')
//                 sp.push(s[i]);

//             else if(s[i] == '*')
//                 sp.pop();
//         }
        
//         while(!sp.empty())
//         {
//             char res = sp.top();
//             sp.pop();
//             ans.push_back(res);
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

