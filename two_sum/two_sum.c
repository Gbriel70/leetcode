#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000000

// HASH ARRAY
typedef struct 
{
    int nbr;
    int index;
} HashEntry;

// HASHMAP
typedef struct
{
    HashEntry *table[TABLE_SIZE];
}  HashMap;

// CALCULATE HASH
int hash(int key)
{
    return abs(key) % TABLE_SIZE;
}

// CREATE HASHMAP
HashMap* createHshMap()
{
    HashMap *map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < TABLE_SIZE; i++)
        map->table[i] = NULL;
    return map;
}

// INSERT INTO HASHMAP
void insert(HashMap *map, int key, int value)
{
    int hashIndex = hash(key);
    while (map->table[hashIndex] != NULL)
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    map->table[hashIndex] = (HashEntry*)malloc(sizeof(HashEntry));
    map->table[hashIndex]->nbr = key;
    map->table[hashIndex]->index = value;
}

// GET HASH
int get_hash(HashMap *map, int key)
{
    int hashIndex = hash(key);
    while (map->table[hashIndex] != NULL)
    {
        if (map->table[hashIndex]->nbr == key)
            return map->table[hashIndex]->index;
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    }
    return -1;
}

// FREE HASHMAP
void freeHashMap(HashMap *map)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (map->table[i] != NULL)
            free(map->table[i]);
    }
    free(map);
}

// TWO SUM
int* TwoSum(int *nums, int numsSize, int target, int *returnSize)
{
    HashMap *map = createHshMap();

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        int index = get_hash(map, complement);
        if (index != -1)
        {
            int *result = (int*)malloc(sizeof(int) * 2);
            result[0] = index;
            result[1] = i;
            *returnSize = 2;
            freeHashMap(map);
            return result; 
        }
        insert(map, nums[i], i);
    }
    *returnSize = 0;
    freeHashMap(map);
    return NULL;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int *result = TwoSum(nums, 4, target, &returnSize);
    if (result != NULL)
    {
        for (int i = 0; i < returnSize; i++)
            printf("%d ", result[i]);
        printf("\n");
        free(result);
    }
    return 0;
}
