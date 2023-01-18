class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ']')
                st.push(s[i]);

            else
            {
                string curr_str = "";
                while (st.top() != '[')
                {
                    curr_str = st.top() + curr_str;
                    st.pop();
                }
                st.pop(); // for '['
                string number = "";

                // for calculating number
                while (!st.empty() && isdigit(st.top()))
                {
                    number = st.top() + number;
                    st.pop();
                }
                int k_time = stoi(number); // convert string to number

                while (k_time--)
                    for (int p = 0; p < curr_str.size(); p++)
                        st.push(curr_str[p]);
            }
        }

        s = "";
        while (!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};

// class Solution
// {
// public:
//     // Function to help repeat the substring a number of times
//     string repeat(string str, int times)
//     {
//         string result = "";
//         for (int i = 0; i < times; i++)
//             result += str;
//         return result;
//     }
//     string decodeString(string s)
//     {
//         int i = 0;
//         while (i < s.size())
//         {
//             if (s[i] != ']')
//             {
//                 i++;
//                 continue;
//             }
//             // The string that needs to get repeated after the first parenthesis '['
//             int j = i;
//             while (s[j] != '[')
//                 j--;
//             // The letters that we will be repeating
//             string repeatLetters = s.substr(j + 1, i - j - 1);
//             int k = j;
//             j--;
//             // checking the number before opening the parenthesis so we can get a count that how many times we need to repeat the strin
//             while ((j > 0) && (isdigit(s[j])))
//                 j--;

//             // Corner case : When we r at the start of our string
//             if (j != 0)
//                 j++;
//             // Find the number of times the letter should be repeated
//             int repeatTimes = stoi(s.substr(j, k - j));
//             // replace the encoded part of string with decoded part
//             s.replace(j, i - j + 1, repeat(repeatLetters, repeatTimes));
//             // Putting i in the right place of our string
//             i = j + repeatLetters.size() * repeatTimes;
//         }
//         return s;
//     }
// };