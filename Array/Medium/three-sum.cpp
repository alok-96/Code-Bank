// https://leetcode.com/problems/3sum/

// T.C. - O(n^2), S.C. - O(n)
// sort the array. run a loop for i. for j and k use two pointer. when we get three numbers sums to 0 put this vector into 
// the set to overcome the duplicacy and at last insert these set element to vector and return.

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> v;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    s.insert(temp);
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else
                    k--;
            }
        }

        for (auto x : s)
            v.push_back(x);

        return v;
    }
};