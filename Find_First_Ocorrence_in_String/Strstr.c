#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle)
{
    if (!*needle) return -1;
    int len = strlen(needle);

    for (int i = 0; haystack[i]; i++)
    {
        if (haystack[i] == needle[0])
        {
            int j = 0;
            while (needle[j] && haystack[i + j] == needle[j])
                j++;
            if (j == len) return i;
        }
    }
    return -1;
}

int main()
{
    char haystack[] = "hello";
    char needle[] = "y";
    int index = strStr(haystack, needle);
    printf("%d\n", index);
    return 0;
}