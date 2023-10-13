// https://leetcode.com/problems/container-with-most-water/

//Naive solution - Time - O(n^2), space - O(1)
//find the minimum height between two heights and calculate the water contained between them. j-i is no. of spaces between these two 

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0, n = height.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = max(ans, min(height[j], height[i]) * (j - i));
            }
        }
        return ans;
    }
};

// Efficient solution - Time - O(n), space - O(1)
// Two pointer approach - move the pointer that points to the lower line. 

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0, n = height.size();
        int i = 0, j = n - 1;

        while (i < j)
        {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            (height[i] < height[j]) ? i++ : j--;
        }

        return ans;
    }
};