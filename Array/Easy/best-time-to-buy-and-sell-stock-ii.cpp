// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

// T.C. - O(n), S.C. - O(1)
// if the price at current day is greater than price at previous day then buy the stock at previous day and 
// sell it on the current day and then calculate profit

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }

        return profit;
    }
};