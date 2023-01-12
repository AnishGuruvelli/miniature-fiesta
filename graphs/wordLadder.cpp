// So, all this problem is asking us to do, is find a shortest path from our start word to end word using only word inside our list. Now any time you think, find the shortest sequence you should immediately think, alright i need to use some shortest path algorithm like Breadth-First-Search (so queue).

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<string> todo;
        todo.push(beginWord);
        
        int ladder = 1;
        
        while (!todo.empty())
        {
            int n = todo.size();
            for (int i = 0; i < n; i++)
            {
                string word = todo.front();
                todo.pop();
                
                if (word == endWord)
                    return ladder;

                dict.erase(word);
                // if this isnt there then time limit exceeded error
                
                for (int j = 0; j < word.size(); j++)
                {
                    char c = word[j];
                    for (int k = 0; k < 26; k++)
                    {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end())
                        {
                            todo.push(word);
                        }
                    }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};