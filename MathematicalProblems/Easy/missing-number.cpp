// https://leetcode.com/problems/missing-number/

// T.C. - O(n), S.C. - O(1)
// calulate the sum upto n numbers and tehn subract sum of numbers in the array from it.

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size(), s = 0;
        for (auto x : nums)
            s += x;

        int sum = (n * (n + 1)) / 2;

        return sum - s;
    }
};