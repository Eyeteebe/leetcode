#include <stdio.h>
#include <stdlib.h>

// int comparator(const void * a,const void * b)
// {
//     return *(int *)a > *(int * )b;
// }
int* twoSum(int* nums, int numsSize, int target) {
    // qsort(nums,numsSize,sizeof(int),comparator);
    int * index;
    index = (int *)calloc(2,sizeof(int));
    for(int i=0;i < numsSize;i++)
    {
        // printf("num:%d\n",nums[i]);
        // if(nums[i] > target)
        //     break;
        for(int j =i+1;j < numsSize;j++)
        {
            // if(nums[j] > target)
            //     break;
            if(nums[i] + nums[j] == target)
            {
                index[0] = i;
                index[1] = j;
                return index;
            }
        }
    }
    return NULL;
}


int main(int argc, char const *argv[])
{
    int num[] = {-3, 4, 3, 90};
    int numsSize = sizeof(num)/sizeof(int);
    int target = 0;
    int * index = twoSum(num,numsSize,target);
    if(index !=NULL)
    {
        for(int i =0;i<2;i++)
        {
            printf("%d\n",*(index + i));
        }
        free(index);
    }
    else
        printf("no index!!\n");
    return 0;
}
