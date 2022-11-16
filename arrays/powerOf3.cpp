class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        if(n==1) return true;
        while(n%3 == 0){
            n = n/3;
        }
        return n==1;
    }
};

// class Solution {
// public:
//     bool helper(int no){
//         int final_no = no%3;
//         if(final_no == 0){
//             helper(final_no);
//         }
//         else{
//             return false;
//         }
//         return true;
//     }
//     bool isPowerOfThree(int n) {
//         return helper(n);
//     }
// };

