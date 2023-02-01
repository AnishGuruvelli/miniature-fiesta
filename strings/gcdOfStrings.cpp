class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        // we cant do this because
        // str1 =
        // "ABABAB"
        // str2 =
        // "ABAB"
        // Output
        // "ABAB"
        // Expected
        // "AB"
        // return str1 + str2 == str2 + str1 ? str2 : "";

        return str1 + str2 == str2 + str1 ? str1.substr(0, gcd(str1.size(), str2.size()))
                                          : "";
    }
};

// class Solution
// {
// public:
//     string gcdOfStrings(string str1, string str2)
//     {
//         if (str1 + str2 != str2 + str1)
//             return "";
//         int len1 = str1.length();
//         int len2 = str2.length();
//         int gcdLength = gcd(len1, len2);
//         return str1.substr(0, gcdLength);
//     }
// };