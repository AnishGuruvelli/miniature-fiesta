class Solution
{
public:
    string addBinary(string a, string b)
    {
        int sum = 0;
        int n = a.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == '1')
            {
                sum += pow(2, n - i - 1);
            }
            else if (a[i] == '0')
            {
                sum += 0;
            }
        }
        int sum2 = 0;
        int n2 = b.size();
        for (int i = n2 - 1; i >= 0; i--)
        {
            if (b[i] == '1')
            {
                sum2 += pow(2, n2 - i - 1);
            }
            else if (b[i] == '0')
            {
                sum2 += 0;
            }
        }
        int sumF = sum + sum2;
        cout << sum << " " << sum2 << " ";
        cout << sumF << " ";

        int binaryNum[32];

        // counter for binary array
        int i = 0;
        while (sumF > 0)
        {
            // storing remainder in binary array
            binaryNum[i] = sumF % 2;
            sumF = sumF / 2;
            i++;
        }
        // printing binary array in reverse order
        //     for (int j = i - 1; j >= 0; j--)
        //         cout << binaryNum[j];
        int reversed_number = 0, remainder;

        while (binaryNum != 0)
        {
            remainder = binaryNum % 10;
            reversed_number = reversed_number * 10 + remainder;
            binaryNum /= 10;
        }

        string stri = to_string(reversed_number);

        return stri;
    }
};