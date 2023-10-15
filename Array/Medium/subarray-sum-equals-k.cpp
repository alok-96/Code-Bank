// https://leetcode.com/problems/subarray-sum-equals-k/

// Naive approach - T.C. - O(n^2), S.C. - O(1)
// go with all subarrays

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
};



// Efficient Approach - T.C. - O(n), S.C. - O(n)
// Using hash map with storing prefix sum into it 
// In each iteration, add current element to variable sum and check if it is equal to k the count++ and again check if sum - k 
// is present in the hashmap(if teh sum-k is preenet that means from that inde to the current index elemnt sums to k) 
// then add the frequency to the count.

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), count = 0, sum = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum == k)
                count++;
            if (mp.find(sum - k) != mp.end())
                count += mp[sum - k];

            mp[sum]++;
        }
        return count;
    }
};