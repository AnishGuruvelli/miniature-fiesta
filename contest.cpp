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

class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> ans;
        string s;
        for (int i = 0; i < nums.size(); i++)
        {
            s += to_string(nums[i]);
        }

        for (int i = 0; i < s.length(); i++)
        {
            ans.push_back(s[i] - '0');
        }

        return ans;
    }
};

class Solution
{
public:
    int minMaxDifference(int no)
    {
        string str = to_string(no);
        int maxi = no, mini = no;

        for (char i = '0'; i <= '9'; ++i)
        {
            for (char j = '0'; j <= '9'; ++j)
            {
                if (i == j)
                    continue;

                // Replace all occurrences of digit i with j
                replace(str.begin(), str.end(), i, j);
                int new_no = stoi(str);

                // Update max and min values
                if (new_no > maxi)
                    maxi = new_no;
                if (new_no < mini)
                    mini = new_no;

                // Reset str to the original value
                str = to_string(no);
            }
        }

        return maxi - mini;
    }
};

class Solution
{
public:
    int minImpossibleOR(vector<int> &nums)
    {
        const int MAX_NUM = 1 << 20; // 2^20, the maximum possible value of OR over a subsequence of nums
        vector<bool> dp(MAX_NUM, false);
        dp[0] = true; // base case
        for (int x : nums)
        {
            for (int i = MAX_NUM - 1; i >= 0; i--)
            {
                if (dp[i])
                {
                    dp[i | x] = true;
                }
            }
        }
        for (int i = 1; i < MAX_NUM; i++)
        {
            if (!dp[i])
            {
                return i;
            }
        }
        return MAX_NUM;
    }
};
