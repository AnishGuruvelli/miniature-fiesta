#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string temp)
{
    int a = 0, b = temp.size() - 1;
    while (a < b)
        if (temp[a++] != temp[b--])
            return false;

    return true;
}

int main()
{
    // Write C++ code here
    string s = "samurai tsunami pot gog bob";
    vector<string> v;
    int n = s.size();

    int start = 0, end = 0;
    while (end < n)
    {
        while (end < n && s[end] != ' ')
            end++;
        string temp = s.substr(start, end - start);
        if (isPalindrome(temp))
            v.push_back(temp);
        start = ++end;
    }

    for (auto i : v)
        cout << i << " ";
    return 0;
}

for (int i = 0; i < s.size(); i++)
{
    for (int j = i + 1; j < s.size(); j++)
    {
        if (s[j] == ' ')
        {
            string temp = s.substr(i, j - i);

            if (palindrome(temp))
                v.push_back(temp);
        }
    }
}