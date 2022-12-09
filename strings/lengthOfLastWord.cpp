class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.size() - 1;
        int j;
        while (i >= 0 && s[i] == ' ')
            i--;
        j = i;
        while (j >= 0 && s[j] != ' ')
            j--;
        return i - j;
    }
};

// int lengthOfLastWord(string s) {
//     int n=s.length()-1;
//     int len=0;
//     while(s[n]==' '){
//         n--;
//     }
//     for(int i=n;i>=0;i--){
//         if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z'))
//             len++;
//         else break;
//     }
//     return len;
// }