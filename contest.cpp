#include <iostream>
using namespace std;

int main()
{
    cin >> n;
    int a1,b1;
    cin >> a1 >> b1;
    while (n--)
    {
        
        int a2, b2;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == q[i])
                a2++;
        }
        for (int j = p.size() - 1; j >= 0; j++)
        {
            if (p[j] == q[j])
                b2++;
        }

        if (a1 == a2 && b1 == b2)
            return "Yes";
        else
            return "No";
    }
    return 0;
}
