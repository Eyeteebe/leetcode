#include <stdio.h>
#include <stdlib.h>

//维持两个变量
int maxProfit(int* prices, int pricesSize) {
    int maxProfit = 0;
    int minprices = 0x7fffffff;
    for(int i = 0;i < pricesSize;i++)
    {
        if(prices[i] < minprices)
            minprices = prices[i];
        if(prices[i] - minprices > maxProfit)
            maxProfit = prices[i] - minprices;
    }
    return maxProfit;
}
int main()
{
    int a[] = {1,2,4,2,5,7,2,4,9,0};
    int length = sizeof(a) / sizeof(int);
    printf("%d\n",length);
    printf("%d\n",maxProfit(a,length));
    return 0;
}