using LL = long long;
class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        int Bulky = max({length, width, height}) >= 10000 or (LL) length * width * height >= 1000000000;
        int Heavy = mass >= 100;
        if (Bulky and Heavy)
            return "Both";
        if (Bulky)
            return "Bulky";
        if (Heavy)
            return "Heavy";
        return "Neither";
    }
};

class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        const int N = 1e5 + 5;
        int f[N];
        bool ban[N];
        memset(ban, false, sizeof ban);
        for (int i : banned)
            ban[i] = true;

        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; ++i)
            if (!ban[i])
                for (int j = maxSum; j >= i; --j)
                    f[j] = max(f[j], f[j - i] + 1);

        return f[maxSum];
    }
};

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
       vector<int>ans; 
       string s;
       for(int i=0;i<nums.size();i++)
       {
           s+=to_string(nums[i]);
       }
        
       for(int i=0;i<s.length();i++)
       {
           ans.push_back(s[i]-'0');
       }
        
        return ans;
    }
};