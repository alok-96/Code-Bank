// https://leetcode.com/problems/find-all-duplicates-in-an-array

// Naive approach - T.C. - O(n), S.C. - O(n)
// Using frequency array

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> v;
        unordered_map<int, int> mp;

        for (auto x : nums)
            mp[x]++;

        for (auto x : mp)
        {
            if (x.second > 1)
                v.push_back(x.first);
        }

        return v;
    }
};

// Efficient approach - T.C. - O(n), S.C. - O(1)
// Negative index marking approach

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> v;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
                v.push_back(abs(nums[i]));
            else
                nums[abs(nums[i]) - 1] *= -1;
        }

        return v;
    }
};