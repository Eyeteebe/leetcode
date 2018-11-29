#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    if(len == 0)
        return 0;
    char *substring;
    int maxlen = 1;
    substring = (char*)malloc(sizeof(char)*len);
    substring[0] = s[0];
    substring[1] = '\0';
    for(int i = 1;i<len;i++)
    {
        char tmp[2];
        tmp[0] = s[i];
        tmp[1] = '\0';
        char * match = strstr(substring,tmp);
        if(match== NULL)
        {
            int index = strlen(substring);
            substring[index] = s[i];
            substring[index+1] = '\0';
        }
        else
        {
            strcpy(substring,match+1);
            int index = strlen(substring);
            substring[index] = s[i];
            substring[index+1] = '\0';
        }
        int cur_len = strlen(substring);
        if(cur_len > maxlen)
            maxlen = cur_len;
    }

    free(substring);
    return maxlen;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("please input the right format!\n");
        return -1;
    }
    char * s = argv[1];
    printf("%d\n",lengthOfLongestSubstring(s));
}
