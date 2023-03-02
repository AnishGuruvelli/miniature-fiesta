class Solution
{
public:
    int compress(vector<char> &chars)
    {
        unordered_map<char, int> mp;
        string str = "";

        for (int i = 0; i < chars.size(); i++)
        {
            if (mp.count(chars[i]) || mp.empty())
                mp[chars[i]]++;
            else if (mp.size() > 0)
            {
                string temp = to_string(mp[chars[i - 1]]);
                str += chars[i - 1];
                if (temp.compare("1") != 0)
                    str += temp;
                // if (mp[chars[i - 1]] > 1)
                //     for (auto t : temp)
                //         str.push_back(t);
                mp.clear();
                mp[chars[i]] = 1;
            }
        }

        string temp1 = to_string(mp[chars[chars.size() - 1]]);
        str += chars[chars.size() - 1];
        if (temp1.compare("1") != 0)
            str += temp1;

        for (int i = 0; i < str.length(); i++)
            chars[i] = str[i];

        return str.length();
    }
};

// class Solution
// {
// public:
//     int compress(vector<char> &chars)
//     {
//         if (chars.empty())
//             return 0;
//         char curr = chars[0];
//         int count = 1;
//         string s;

//         for (int i = 1; i <= chars.size(); i++)
//         {
//             if (i < chars.size() && chars[i] == curr)
//                 count++;
//             else
//             {
//                 s.push_back(curr);
//                 if (count > 1)
//                 {
//                     string str = to_string(count);
//                     for (char c : str)
//                         s.push_back(c);
//                 }
//                 curr = i < chars.size() ? chars[i] : 0;
//                 count = 1;
//             }
//         }
//         for (int i = 0; i < s.size(); i++)
//             chars[i] = s[i];

//         return s.size();
//     }
// };