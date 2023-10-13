//https://leetcode.com/problems/two-sum/

//Naive pproach - T.C. - O(n^2) S.C. - O(1)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == target - nums[i])
                {
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
        }

        return v;
    }
};

// Efficient approach - T.C. - O(n) S.C. - O(n) double pass
// Store the number along with index. Iterate array and serch for in map that the target - nums[i] is present in the hash map.

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.count(target - nums[i]) && mp[target - nums[i]] != i)
            {
                v.push_back(i);
                v.push_back(mp[target - nums[i]]);
                break;
            }
        }

        return v;
    }
};


// Another Efficient approach - T.C. - O(n) S.C. - O(n) single pass
// before storing the number along with index first search for the target - nums[i] in hash map. If found then retrun answer else store it on the map. 

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.count(target - nums[i]))
            {
                v.push_back(i);
                v.push_back(mp[target - nums[i]]);
                break;
            }
            else
                mp[nums[i]] = i;
        }

        return v;
    }
};