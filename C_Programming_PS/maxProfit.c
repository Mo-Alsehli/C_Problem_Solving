#include <stdio.h>

/*
Prob Definition:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

-- Solution
In this code, we define the maxProfit function that takes an array of prices and its size as input. We initialize minPrice to the first price in the array and maxProfit to 0. Then, we iterate over the prices starting from the second day. If the current price is lower than the minPrice, we update minPrice. Otherwise, we calculate the potential profit by subtracting minPrice from the current price. If the potential profit is greater than maxProfit, we update maxProfit. Finally, we return maxProfit.

*/

int maxProfit(int *prices, int pricesSize)
{
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        else
        {
            int potentialProfit = prices[i] - minPrice;
            if (potentialProfit > maxProfit)
            {
                maxProfit = potentialProfit;
            }
        }
    }

    return maxProfit;
}

int main()
{
    // Example usage
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    int profit = maxProfit(prices, pricesSize);
    printf("Max Profit: %d\n", profit);

    return 0;
}
