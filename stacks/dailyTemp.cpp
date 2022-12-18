class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &t)
    {
        int n = t.size();

        vector<int> ans(n, 0);
        
        stack<int> st;
        
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && t[i] > t[st.top()])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;

        // tried but not working

        // vector<int> ans;
        // int i, j, res = 0;
        // for(i=0;i<temperatures.size()-1;i++){
        //     if(temperatures[i]>temperatures[i+1]){
        //         for(j=i+1;j<temperatures.size()-1;j++){
        //             if(temperatures[i]>temperatures[j]){
        //                 res = j;
        //             }
        //         }
        //         ans.push_back(j-i);
        //     }
        //     else ans.push_back(1);
        // }
        // if(i==temperatures.size()-1) ans.push_back(0);

        // return ans;
    }
};