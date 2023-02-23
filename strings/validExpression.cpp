// https://www.codechef.com/problems/EVALMAS?tab=statement

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        string ans = "";
        if (x <= n + 1 && x >= 1 - n)
        {
            int total = 1;
            for (int i = 0; i < n; i++)
            {
                if (total < x)
                {
                    total++;
                    ans += "+";
                }
                else if (total > x)
                {
                    total--;
                    ans += "-";
                }
                else
                    ans += "*";
            }
            cout << ans << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
