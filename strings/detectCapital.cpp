class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int count = 0;
        
        for (auto i : word)
            if (i >= 'A' && i <= 'Z')
                count++;

        if (count == 0)
            return true;
        
        if (count == 1)
        {
            if (word[0] >= 'A' && word[0] <= 'Z')
                return true;
            else
                return false;
        }
        
        return count == word.size() ? true : false;
    }
};