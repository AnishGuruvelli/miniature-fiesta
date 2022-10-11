class Solution
{
public:
    vector<vector> groupAnagrams(vector &strs)
    {
        map<pair<long long, long long>, vector> hash;
        for (int i = 0; i < strs.size(); i++)
        {
            pair<long long, long long> temp;
            temp.first = 0;
            temp.second = 0;
            string s = strs[i];
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] < 'm')
                    temp.second += pow(10, (s[j] - 'a'));
                else
                    temp.first += pow(10, s[j] - 'm');
            }
            hash[temp].push_back(s);
        }
        vector<vector> ans;
        for (auto i : hash)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};