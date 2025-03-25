#include <stdio.h>
#include <string.h>

int removeElement(int* nums, int numsSize, int val)
{
    if (numsSize == 0) return 0;
    int i = 0;
    for (int j = 0; j < numsSize; j++)
    {
        if (nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main()
{
    int nums[] = {3, 2, 2, 1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 2;
    int new_size = removeElement(nums, numsSize, val);
    for (int i = 0; i < new_size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("%d\n", new_size);
    return 0;
}