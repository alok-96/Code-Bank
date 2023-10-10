// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//Efficient Approach -> T.C. - O(n) S.C. - O(1)
//buy on first day initially, traverse into array if arr[i] > buy then calculate profit else update buy = arr[i]

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0, buy = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < buy)
                buy = prices[i];
            else
                profit = max(profit, prices[i] - buy);
        }

        return profit;
    }
};