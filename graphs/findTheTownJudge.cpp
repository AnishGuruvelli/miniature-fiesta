/// VECTOR METHOD

// class Solution
// {
// public:
//     int findJudge(int n, vector<vector<int>> &trust)
//     {
//         vector<int> ans;
//         for (int i = 0; i < trust.size(); i++)
//             ans.push_back(trust[i][1]);

//         ans.erase(unique(ans.begin(), ans.end()), ans.end());
//         return ans.size() == 1 ? ans[0] : -1;
//     }
// };

// this solution doesnt work due to the following testcases
// one person can trust multiple ppl too

// trust =
// [[1,3],[1,4],[2,3],[2,4],[4,3]]

// 55 / 92 testcases passed
// Output
// -1
// Expected
// 3

/// GRAPH METHOD

// Create an array Trusted of size N+1 to represent the total number of people in a town and initialize it with 0
// After initialization, whenever a person trust someone else than himself, the trusted value of that person should be decreased since that person is not satisfying the two conditions that were mentioned in the question.
// Also if a certain x person is trusted by others from town, than this x person value should be increased and those who trusted that x person there values should be decreased.
// At last traverse through every person of town and while traversing If a person is found with N-1 trusts than this person should be the judge and return the index of that person .
// A concept that is used in algo you know but you don't know that you know :))

// In a graph the indegree of a person or node is the number of nodes that trusts a given specific node and outdegree of a person or node is the number of nodes that are trusted by given specific node
// In more technical words:-
// Out-degree is the number of outgoing edges emanating from a node. &
// In-degree is the number of incoming edges onto a node

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> Trusted(N + 1, 0);
        for (auto person : trust)
        {
            Trusted[person[0]]--;
            // you shouldnt trust anyone else
            Trusted[person[1]]++;
            // someone else trusts you so good thing
        }

        for (int i = 1; i <= N; i++)
            if (Trusted[i] == N - 1)
                return i;

        return -1;
    }
};