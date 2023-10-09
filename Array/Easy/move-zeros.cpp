// Naive Approach -> T.C - O(n) S.C - O(1)
//Store non zero elements in order in a vector and then push zero at the last. copy the vector into original vector nums.

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int> v;
        int zeros = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                v.push_back(nums[i]);
            else
                zeros++;
        }

        while (zeros--)
            v.push_back(0);

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = v[i];
        }
    }
};



//Optimised Approach -> T.C. - O(n)  S.C. - O(1)
//Use two pointers - current Index to traverse the array and lastNOnZeroIndex to keep track index of last non zero element.
//If nums[i] != 0 then swap the element at index currentIndex and lastNonZeroIndex.

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int lastNonZeroIndex = -1, currentIndex = 0; currentIndex < nums.size(); currentIndex++)
        {
            if (nums[currentIndex] != 0)
            {
                lastNonZeroIndex++;
                swap(nums[lastNonZeroIndex], nums[currentIndex]);
            }
        }
    }
};