// https://www.geeksforgeeks.org/chocolate-distribution-problem/

//Efficient Approach -> T.C. - O(n) , S.C. - O(1)
//sort the array, use to pointer - i for starting of the window and j for end of the window.
//Iterate the loop while j reaches to last index of array and calculate the min difference by increasin the window size by 1.

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {

        sort(a.begin(), a.end());
        long long i = 0, j = m - 1;

        long long ans = INT_MAX;
        while (j < n)
        {
            ans = min(ans, a[j] - a[i]);
            i++;
            j++;
        }

        return ans;
    }
};