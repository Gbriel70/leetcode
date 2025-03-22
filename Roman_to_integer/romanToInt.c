#include <stdio.h>

int romanToInt(char *s)
{
    int *roman = (int[126]){0};
    roman['I' - 'A'] = 1;
    roman['V' - 'A'] = 5;
    roman['X' - 'A'] = 10;
    roman['L' - 'A'] = 50;
    roman['C' - 'A'] = 100;
    roman['D' - 'A'] = 500;
    roman['M' - 'A'] = 1000;

    int res = 0;
    while (*s)
    {
        if (roman[*s - 'A'] < roman[*(s + 1) - 'A'])
            res -= roman[*s - 'A'];
        else
            res += roman[*s - 'A'];
        s++;
    }
    return res;
}

int main(void)
{
    char *s = "MCMXCIV";
    printf("%d\n", romanToInt(s));
    return 0;
}