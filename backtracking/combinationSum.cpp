class Solution {
public:
    vector<vector<int>> result;
    
    void comSum(vector<int> &curr, int curInd, int sum, vector<int> &candidates, int target, int n){
        if(sum == target){
            result.push_back(curr);
            return;
        }      
        else if(sum > target){
            return;
        }
        
        for(int i = curInd; i < n; i++){
            curr.push_back(candidates[i]);
            sum += candidates[i];
            comSum(curr, i, sum, candidates, target, n);
            sum -= candidates[i];
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        int sum = 0;
        int n = candidates.size();
        comSum(curr, 0, sum, candidates, target, n);
        return result;
    }
};


// // https://www.youtube.com/watch?v=OyZFFqQtu98

// class Solution
// {
// public:
//     void findCombination(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
//     {
//         if (index == arr.size())
//         {
//             if (target == 0)
//                 return ans.push_back(ds);
//             return;
//         }

//         // pickup the element
//         if (arr[index] <= target)
//         {
//             ds.push_back(arr[index]);
//             findCombination(index, target - arr[index], arr, ans, ds);
//             ds.pop_back();
//         }
//         // dont pick up the element
//         findCombination(index + 1, target, arr, ans, ds);
//     }

//     vector<vector<int>> combinationSum(vector<int> &candidates, int target)
//     {
//         vector<vector<int>> ans;
//         vector<int> ds;

//         findCombination(0, target, candidates, ans, ds);

//         return ans;
//     }
// };