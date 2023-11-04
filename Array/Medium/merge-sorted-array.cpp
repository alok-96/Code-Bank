// https://leetcode.com/problems/merge-sorted-array/

// T.C. -> O(m+n), S.C. -> O(m+n)
// Used the concept of Merge sort, by using another array to store elements first and then copied 
// them into nums1

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m!= 0 && n != 0)
        {
            int i=0, j=0;
            vector<int>v;

            while(i < m && j < n)
            {
                if(nums1[i] <= nums2[j])
                {
                    v.push_back(nums1[i]);
                    i++;
                }
                else
                {
                    v.push_back(nums2[j]);
                    j++;
                }
            }

            if(i == m)
            {
                while(j < n)
                {
                    v.push_back(nums2[j]);
                    j++;
                }
            }

            if(j == n)
            {
                while(i < m)
                {
                    v.push_back(nums1[i]);
                    i++;
                }
            }

            for(int i=0; i<nums1.size(); i++)
            nums1[i] = v[i];
        }
        else if(m == 0 && n != 0)
        {
            for(int i=0; i<n; i++)
            nums1[i] = nums2[i];
        }
    }
};


// Efficient Approach
// T.C. -> O(m+n), S.C. -> O(1)
// Place greater number at the end of nums1, traverse from last of each arrays 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j = n-1, k= m+n-1;

        while(i >=0 && j>= 0)
        {
            if(nums1[i] >= nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        if(i == -1)
        {
            while(j >= 0)
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
    }
};