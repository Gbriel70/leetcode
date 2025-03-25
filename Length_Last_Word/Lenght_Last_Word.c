#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) 
{
    if (!*s) return 0;
    int i = 0; 
    int j = 0;
    while (s[i]) i++;
    i--;
    while (i >= 0 && s[i] == ' ')i--;
    while (i >= 0 && s[i] != ' ')
    {
        i--;
        j++;
    }
    return j;
}

int main()
{
    char s[] = "Hello World";
    int len = lengthOfLastWord(s);
    printf("%d\n", len);
    return 0;
}