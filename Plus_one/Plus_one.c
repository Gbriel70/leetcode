#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    if (digitsSize == 0) return NULL;
    int carry = 1;
    int *new_digits = (int*)malloc((digitsSize + 1) * sizeof(int));

    for (int i = 0; i < digitsSize; i++)
    {
        new_digits[i] = digits[i];
    }

    for (int i = digitsSize - 1; i >= 0; i--)
    {
        int sum = new_digits[i] + carry;
        new_digits[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0)
    {
        *returnSize = digitsSize + 1;
        for (int i = digitsSize; i > 0; i--)
        {
            new_digits[i] = new_digits[i - 1];
        }
        new_digits[0] = 1;
    }
    else
    {
        *returnSize = digitsSize;
    }
    return new_digits;
}

int main()
{
    int digits[] = {1, 2, 3};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
 
    int returnSize = 0;
    int *new_digits = plusOne(digits, digitsSize, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", new_digits[i]);
    }
    printf("\n");
    free(new_digits);
    return 0;
}