#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    char *stack = (char *)malloc(sizeof(char) * strlen(s));
    if (!stack) return false;
    int j = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[j++] = s[i];
        else if (s[i] == ')' && j > 0 && stack[j - 1] == '(')
            j--;
        else if (s[i] == ']' && j > 0 && stack[j - 1] == '[')
            j--;
        else if (s[i] == '}' && j > 0 && stack[j - 1] == '{')
            j--;
        else
        {
            free(stack);
            return false;
        }
    }
    bool isValid = (j == 0);
    free(stack);
    return isValid;
}


int main(void)
{
    char s[] = "([])";
    printf("%d\n", isValid(s));
    return 0;
}