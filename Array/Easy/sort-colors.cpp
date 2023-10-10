// https://leetcode.com/problems/sort-colors/

//Naive Approach  - T.C. - O(n) , S.C. - O(1)
//count the frequency of 0, 1 anad 2 and then place them in sorted order in the given array

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int c0 = 0, c1 = 0, c2 = 0;

        for (auto x : nums)
        {
            if (x == 0)
                c0++;
            else if (x == 1)
                c1++;
            else
                c2++;
        }

        int i = 0;
        while (c0--)
            nums[i++] = 0;
        while (c1--)
            nums[i++] = 1;
        while (c2--)
            nums[i++] = 2;
    }
};


//In place change  T.C. - O(n) , S.C. - O(1)
// Using 3 pointer - left, curr, right . letf at 0 curr at 0 and right at n-1. if curr is pointing to 0 swap it with left pointer 
// and if curr pointer pointing to 2 swap it with right pointer

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int left = 0, curr = 0, right = nums.size() - 1;

        while (curr <= right)
        {
            if (nums[curr] == 0)
            {
                swap(nums[curr], nums[left]); // moving 0 to left
                left++;
                curr++;
            }
            else if (nums[curr] == 2)
            {
                swap(nums[curr], nums[right]); // moving 2 to right
                right--; // don't move current to next position because 0 may come at that position after swapping
            }
            else if (nums[curr] == 1)
                curr++;
        }
    }
};