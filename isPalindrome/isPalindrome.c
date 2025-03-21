#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int rev = 0;
    int tmp = x;
    while (tmp)
    {
        if (rev > (INT_MAX / 10))
            return false;
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    return rev == x;
}

int main(void)
{
    int nbr = 1234567899;
    printf("%d\n", isPalindrome(nbr));
    return 0;
}