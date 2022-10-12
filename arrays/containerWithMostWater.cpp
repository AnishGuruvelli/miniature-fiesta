class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int width = r - l;

            int h = min(height[l], height[r]);

            int area = h * width;

            int maxarea = max(area, maxarea);

            if (height[l] > height[r])
                r--;

            else if (height[l] < height[r])
                l++;

            else
            {
                l++;
                r--;
            }
        }
        return maxarea;
    }
};