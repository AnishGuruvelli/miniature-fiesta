// This problem is same as longest increasing subsequence and we can solve this problem using dynamic programming.

// Approach for this Problem:
//     Create a pair array of size n where n is the size of scores and ages arrays.
//     Store each player's score and age as a pair in the above array.
//     Sort the pair array in increasing order of age.
//     Initialize an array dp of size n and set dp[i] to be the score of player i for all 0 <= i < n.
//     Initialize a variable ans to store the maximum overall score.
//     Loop through the pair array from index i = 0 to i = n - 1.
//     For each i, loop through j from 0 to i - 1.
//     If the score of player j is less than or equal to the score of player i,
//     update dp[i] to be the maximum of dp[i] and dp[j] + score[i].
//     Set ans to be the maximum of ans and dp[i].
//     Return ans as the result.

class Solution
{
public:
    // Driver function to sort the vector elements
    // by first element of pairs
    // static bool sortbyfirst(const pair<int, int> &a,
    //                  const pair<int, int> &b)
    // {
    //     return (a.first < b.first);
    // }
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        int dp[n], ans = 0;
        vector<pair<int, int>> players;
        for (int i = 0; i < n; i++)
            players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());
        // BY DEFAULT, IT WILL SORT ACCORDING TO THE FIRST PARAMETER IN THE PAIR IN VECTORS
        // sort(players.begin(), players.end(), sortbyfirst);

        // third test case
        // 5 1 2 3

        for (int i = 0; i < n; i++)
        {
            dp[i] = players[i].second;
            for (int j = 0; j < i; j++)
                if (players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};