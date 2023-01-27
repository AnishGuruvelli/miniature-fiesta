class Solution
{
    struct TrieNode
    {
        TrieNode *arr[26];
        bool is_end;
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
                arr[i] = NULL;
            is_end = false;
        }
    };

    void insert(TrieNode *root, string key)
    {
        TrieNode *curr = root;
        for (int i = 0; i < key.size(); i++)
        {
            int idx = key[i] - 'a';
            if (curr->arr[idx] == NULL)
                curr->arr[idx] = new TrieNode();
            curr = curr->arr[idx];
        }
        curr->is_end = true;
    }

    bool dfs(TrieNode *root, string key, int index, int count)
    {
        if (index >= key.size())
            return count > 1;
        TrieNode *curr = root;
        for (int i = index; i < key.size(); i++)
        {
            int p = key[i] - 'a';
            if (curr->arr[p] == NULL)
                return false;

            curr = curr->arr[p];
            if (curr->is_end)
                if (dfs(root, key, i + 1, count + 1))
                    return true;
        }
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(root, words[i]);

        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
            if (dfs(root, words[i], 0, 0))
                ans.push_back(words[i]);

        return ans;
    }
};

/*

For those doing the January challenge, this is the first word tree question, and they start with a hard.

So a tip is to make a "tree" made out of the characters of the words. Each level of the tree has the ith character of each word. And mark at each level if a word has ended there or not.

After you make this tree, then it is a medium dp question to check if a word is made up of words.


Intuition :

    We can use the data structure trie to store the words. Then for each word in the list of words, we use depth first search to see whether it is a concatenation of two or more words from the list.

    We first build a trie structure that stores the list of words. In every trie node, we use an array of length 26 to store possible next trie node, and a flag to indicate whether the trie node is the last letter of a word in the dictionary.

*/

// https://leetcode.com/problems/concatenated-words/solutions/3103680/clean-codes-full-explanation-trie-dfs-c-java-python3/?orderBy=most_votes&languageTags=cpp&topicTags=trie
