#include <stdio.h>
#include <string.h>

int searchInsert(int* nums, int numsSize, int target)
{
    if (numsSize == 0) return 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >= target) return i;
    }
    return numsSize;
}

int main()
{
    int nums[] = {1, 3, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 5;
    int index = searchInsert(nums, numsSize, target);
    printf("%d\n", index);
    return 0;
}