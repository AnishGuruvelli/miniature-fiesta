class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < tasks.size(); i++)
            mp[tasks[i]]++;

        int output = 0;

        for (auto freq : mp)
        {
            if (freq.second == 1)
                return -1;

            if (freq.second % 3 == 0)
                output += freq.second / 3;

            else
                output += freq.second / 3 + 1;
        }
        return output;
    }
};

// From observation, we can see that there's only 3 possible outcomes.

//     If the frequency is 1, the task cannot be performed so we return -1.
//     If the frequency is 3, the task can be performed and we return frequency/3.
//     Now if the frequency is not completely divisible by 3, then the possible remainders are 1 and 2. Lets check them out:

//     If remainder is 1, i.e, lets take 7 frequency, then 🔮🔮🔮🔮🔮🔮🔮 the groups are something like this "🔮🔮🔮" "🔮🔮🔮" "🔮", i.e, one 🔮 is left alone so the solution is to break the second last group into two parts of 2 and 1 so that it becomes like: "🔮🔮🔮" "🔮🔮" "🔮🔮", i.e, one is added to the division by 3.
//     If remainder is 2, i.e, lets take 8 frequency, then 🔮🔮🔮🔮🔮🔮🔮🔮 the groups are something like this "🔮🔮🔮" "🔮🔮🔮" "🔮🔮", i.e, two 🔮 are left so the solution is to just add 1,i.e, one group of two to the solution.