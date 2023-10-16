// https://leetcode.com/problems/majority-element/

// Naive Approach - T.C. - O(n), S.C. - O(n)
// Using hash map(frequency array)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (auto x : nums)
        {
            mp[x]++;
        }

        for (auto x : mp)
        {
            if (x.second > nums.size() / 2)
                return x.first;
        }
        return -1;
    }
};

// Efficient Approach - T.C. - O(n), S.C. - O(1)
// Using Majority Voting Algorithm
// let 0th element is majority element and count = 1. if next element is same as majority element the count++. if not thrn count--.
// if count reaches to 0 then let majority element is ith element and count = 1. At last which element is stored in majority element 
// varaible, that will be the majority element.

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1, majorityEle = nums[0];
        for (auto x : nums)
        {
            if (x == majorityEle)
                count++;
            else
                count--;
            if (count == 0)
            {
                majorityEle = x;
                count = 1;
            }
        }
        return majorityEle;
    }
};