#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    int i = 0;
    int valley = prices[0];
    int peak = prices[0];
    int maxProfit = 0;
    while(i < pricesSize - 1)
    {
        while(i < pricesSize - 1 && prices[i] >= prices[i + 1])
            i++;
        valley = prices[i];
        while(i < pricesSize - 1 && prices[i] <= prices[i + 1])
            i++;
        peak = prices[i];

        maxProfit += peak - valley;

    }
    return maxProfit;
}

int main(int argc, char const *argv[])
{
    int a[] = {1,2,4,2,5,7,2,4,9,0};
    int length = sizeof(a) / sizeof(int);
    printf("%d\n",length);
    printf("%d\n",maxProfit(a,length));
    return 0;
}
