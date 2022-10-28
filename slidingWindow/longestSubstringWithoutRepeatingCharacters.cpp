// https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/2133524/JavaC%2B%2B-A-reall-Detailed-Explanation

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;
        unordered_map<char, int> m;
        int i = 0, j = 0, ans = INT_MIN;
        while (j < s.length())
        {
            m[s[j]]++;
            // increase the frequency of the element as you traverse the string
            if (m.size() == j - i + 1) // whem map size is equal to the window size means suppose window size is 3 and map size is also three that means in map all unique characters are their
            {
                ans = max(ans, j - i + 1); // compare the length of the maximum window size
            }
            else if (m.size() < j - i + 1) // if the map size is less than the window size means there is some duplicate present like window size = 3 and map size = 2 means there is a duplicates
            {
                while (m.size() < j - i + 1) // so till the duplicates are removed completely
                {
                    m[s[i]]--;        // remove the duplicates
                    if (m[s[i]] == 0) // if the frequency becomes zero
                    {
                        m.erase(s[i]); // delete it completely
                    }
                    i++; // go for next element
                }
            }
            j++; // go for the next element
        }
        return ans;
    }
};

/*
To, find out a sliding window problem :-
> First thing is, we have given something like an "Array" | OR | "String"
> Second thing is, they are talking about either "subsequence" | OR | "substring"
> And third most thing is, either we have given a "window size i.e. k" | OR | we have to "manually find out window size"

There's exist basically 2 types of sliding window.
    Fix size sliding window {means K is given}
    Variable silze sliding window {means K is not given}

A template which you can use in any sliding window {Variable size} problem:

while(j < size()){

    // Calculation's happen's here
-----------------------------------------------
    if(condition < k){
        j++;
    }
-----------------------------------------------

-----------------------------------------------
    else if(condition == k){
        // ans <-- calculation
        j++;
    }
----------------------------------------------

----------------------------------------------
    else if(condition > k){
        while(condition > k){
            // remove calculation for i
            i++;
        }
        j++;
    }
----------------------------------------------
}
return ans;
*/