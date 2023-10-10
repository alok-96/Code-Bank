// https://leetcode.com/problems/find-the-duplicate-number/

//Using frequency array T.C.- O(n), S.C. - O(n)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto x : nums)
            mp[x]++;

        for (auto x : mp)
        {
            if (x.second > 1)
                return x.first;
        }
        return -1;
    }
};



//Using negative index approach -> T.C. - O(n), S.C. - O(1)
//make the index negative => if we are at i th index then multiply the index (nums[i] - 1) with -1. 
//and while making negative if the number at that index is negative already that means that element is present already.

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
                return abs(nums[i]); // this is the  duplicate number
            else
                nums[abs(nums[i]) - 1] *= -1;
        }
        return -1;
    }
};