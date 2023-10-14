// https://leetcode.com/problems/4sum/

// T.C. - O(n^3), S.C. - O(n)
// sort the array. run a loop for i. then again a nested loop for j. for k and l use two pointer. when we get four numbers sums 
// to target put this vector into the set to overcome the duplicacy and at last insert these set element to vector and return.

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> v;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int k = j + 1, l = n - 1;
                while (k < l)
                {
                    if (long(nums[i]) + long(nums[j]) + long(nums[k]) + long(nums[l]) == target)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        s.insert(temp);
                        k++;
                        l--;
                    }
                    else if (long(nums[i]) + long(nums[j]) + long(nums[k]) + long(nums[l]) < target)
                        k++;
                    else
                        l--;
                }
            }
        }

        for (auto x : s)
            v.push_back(x);

        return v;
    }
};