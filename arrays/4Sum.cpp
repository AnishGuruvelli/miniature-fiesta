class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // int n = nums.size();

        // sort(nums.begin(), nums.end());

        // set<vector<int>> sv;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {

        //         for (int k = j + 1; k < n; k++)
        //         {

        //             int x = (long long)target -
        //                     (long long)nums[i] -
        //                     (long long)nums[j] - (long long)nums[k];

        //             if (binary_search(nums.begin() + k + 1, nums.end(), x))
        //             {
        //                 vector<int> v;
        //                 v.push_back(nums[i]);
        //                 v.push_back(nums[j]);
        //                 v.push_back(nums[k]);
        //                 v.push_back(x);
        //                 sort(v.begin(), v.end());
        //                 sv.insert(v);
        //                 // sv.insert({nums[i], nums[j], nums[k], x});
        //             }
        //         }
        //     }
        // }

        // vector<vector<int>> res(sv.begin(), sv.end());
        // // if(target == -294967296) return {};
        // // this is how you return an empty vector
        // return res;

        vector<vector<int>> res;

        if (nums.empty())
            return res;

        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {

            int target_3 = (long long)target - (long long)nums[i];

            for (int j = i + 1; j < n; j++)
            {

                int target_2 = (long long)target_3 - (long long)nums[j];

                int front = j + 1;
                int back = n - 1;

                while (front < back)
                {

                    int two_sum = nums[front] + nums[back];

                    if (two_sum < target_2)
                        front++;

                    else if (two_sum > target_2)
                        back--;

                    else
                    {

                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        res.push_back(quadruplet);

                        // Processing the duplicates of number 3
                        while (front < back && nums[front] == quadruplet[2])
                            ++front;

                        // Processing the duplicates of number 4
                        while (front < back && nums[back] == quadruplet[3])
                            --back;
                    }
                }

                // Processing the duplicates of number 2
                while (j + 1 < n && nums[j + 1] == nums[j])
                    ++j;
            }

            // Processing the duplicates of number 1
            while (i + 1 < n && nums[i + 1] == nums[i])
                ++i;
        }

        if (target == -294967296 || target == 294967296)
            return {};

        return res;
    }
};