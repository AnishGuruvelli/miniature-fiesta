using LL = long long;
class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        int Bulky = max({length, width, height}) >= 10000 or (LL) length * width * height >= 1000000000;
        int Heavy = mass >= 100;
        if (Bulky and Heavy)
            return "Both";
        if (Bulky)
            return "Bulky";
        if (Heavy)
            return "Heavy";
        return "Neither";
    }
};