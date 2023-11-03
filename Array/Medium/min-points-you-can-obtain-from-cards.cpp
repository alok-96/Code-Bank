// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

// T.C. -> O(n), S.C. -> O(1)
// First find the sum of all elements. if k == n then return the sum. 
// If not then find the window of n-k containing minimum sum and return sum - minWindowSum.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, n = cardPoints.size();

        for(auto x:cardPoints)
            sum += x;

        if(k == n)
            return sum;

        int windowSize = n-k, windowSum = 0;
        for(int i=0; i<windowSize; i++)
            windowSum += cardPoints[i];
        
        int minWindowSum = windowSum;
        for(int i=windowSize; i<n; i++)
        {
            windowSum = windowSum + cardPoints[i] - cardPoints[i-windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }

        return sum - minWindowSum;
    }
};