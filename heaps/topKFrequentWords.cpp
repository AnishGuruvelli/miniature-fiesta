// https://leetcode.com/problems/top-k-frequent-words/

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {

        unordered_map<string, int> mp;
        vector<string> ans;

        for (int i = 0; i < words.size(); i++)
        {
            mp[words[i]]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        // for (auto it = mp.begin(); it != mp.end(); it++)
        for (auto it : mp)
        {
            pq.push({it->second, it->first});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};


/*
class Solution {
public:
    
    class comp{
        public:
            bool operator()(pair<int,string> &p1,pair<int,string> &p2){
                if(p1.first == p2.first) return p1.second > p2.second;
                return p1.first < p2.first;
            }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        for(auto i : mp){
            pq.push({i.second,i.first});
        }
        while(k--){
            pair<int,string> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};
*/