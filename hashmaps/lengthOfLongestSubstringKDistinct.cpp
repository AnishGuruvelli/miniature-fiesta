lengthOfLongestSubstringKDistinct(string s, int k)
{
    int n = s.size();
    if (n == 0 || k == 0)
        return 0;
    
    unordered_map<char, int> mp;
    int left = 0, right = 0;
    int max_len = 0;
    
    while (right < n)
    {
        mp[s[right]]++;
        while (mp.size() > k)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
            {
                mp.erase(s[left]);
            }
            left++;
        }
        max_len = max(max_len, right - left + 1);
        right++;
    }
    return max_len;
}
