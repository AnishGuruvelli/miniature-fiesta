class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        // for checking if its sorted lexicographically in rows, now we have to check for columns
        // for(auto i: strs){
        //     string a = i;
        //     string b = i;
        //     sort(a.begin(), a.end());
        //     sort(b.rbegin(), b.rend());
        //     if(a == i || b==i) cout<<1<<endl;
        // }
        // return 0;

        int delete_count = 0;
        int row = strs.size();
        int col = strs[0].size();

        for (int j = 0; j < col; j++)
        {
            for (int i = 0; i < row - 1; i++)
            {
                if (strs[i][j] > strs[i + 1][j])
                {
                    delete_count++;
                    break;
                }
            }
        }
        return delete_count;
    }
};