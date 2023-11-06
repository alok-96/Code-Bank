// https://leetcode.com/problems/maximum-product-of-three-numbers/

// T.C. - O(nlogn), S.CC.-> O(1)
// maximun product of three numbers will be either multiplication of last three numbers or
// multiplication of first two numbers wth last number
// Think about this case - [-100,-98,-1,2,3,4]


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
        return ans;
    }
};