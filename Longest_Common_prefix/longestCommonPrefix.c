#include <stdio.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strSize)
{
    if (strSize == 0)
        return "";

    int j = 0;
    while (strs[0][j])
    {
        for (int i = 1; i < strSize; i++)
        {
            if (strs[i][j] != strs[0][j])
            {
                strs[0][j] = '\0';
                return strs[0];
            }
        }
        j++;
    }
    return strs[0];
}

int main(void)
{
    char str1[] = "flower";
    char str2[] = "flow";
    char str3[] = "flight";
    char *strs[] = {str1, str2, str3};
    int strSize = 3;

    printf("%s\n", longestCommonPrefix(strs, strSize));
    return 0;
}