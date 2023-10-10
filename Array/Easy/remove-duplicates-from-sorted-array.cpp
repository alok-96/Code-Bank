// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

//Using two pointer - T.C. - O(n) S.C. - O(1)
//if nums[j] == nums[i] then increment j and if not then swap both numbers at index i and j. 

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0, j = 0;
        while (j < nums.size())
        {
            if (nums[i] == nums[j])
                j++;
            else
            {
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        return i + 1;
    }
};