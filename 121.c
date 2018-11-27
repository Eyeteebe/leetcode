#include <stdio.h>
#include <stdlib.h>

//两个for循环
int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    for(int i =0;i < pricesSize;i ++)
    {
        int max_profit = 0;
        for(int j = i + 1;j < pricesSize;j++)
        {
            int max_profit_temp = 0;
            if(prices[i] < prices[j] )
                max_profit_temp = prices[j] - prices[i];
            if(max_profit_temp > max_profit)
                max_profit = max_profit_temp;
        }
        if(max_profit > max)
            max = max_profit;
    }
    return max;
}
int main()
{
    int a[] = {1,2,4,2,5,7,2,4,9,0};
    int length = sizeof(a) / sizeof(int);
    printf("%d\n",length);
    printf("%d\n",maxProfit(a,length));
    return 0;
}