#include <stdio.h>
#include <stdlib.h>

int calculate(int *prices,int start,int pricesSize)
{
    // printf("start:%d\n",start);
    if(start >= pricesSize)
        return 0;
    int max = 0;
    for(int i =start;i < pricesSize;i++)
    {
        printf("i:%d\n",i);
        int maxprofit = 0;
        for(int j=i+1;j < pricesSize;j++)
        {
            int profit = 0;
            if(prices[j] > prices[i])
                profit = calculate(prices,j,pricesSize) + prices[j] - prices[i];
            // printf("profit:%d\n",profit);
            if(profit > maxprofit)
                maxprofit = profit;
        }

        if(maxprofit > max)
            max = maxprofit;
    }
    return max;
}
int maxProfit(int* prices, int pricesSize) {
    return calculate(prices,0,pricesSize);
}

int main(int argc, char const *argv[])
{
    int a[] = {7,6,4,3,1};
    int length = sizeof(a) / sizeof(int);
    printf("%d\n",length);
    printf("%d\n",maxProfit(a,length));
    return 0;
}
