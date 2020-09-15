/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
#include <stdlib.h>
#include <stdio.h>

typedef struct num {
    int val;
    unsigned int idx;
} num_t;

int numberCompare(const void *a, const void *b)
{
    return ((num_t *)a)->val - ((num_t *)b)->val;
}
/*
void printArr(int *nums, int numsSize)
{
    int i;

    if (!nums || !numsSize) {
        return;
    }
    printf("[");
    for (i = 0;; i++) {
        printf("%d", nums[i]);
        if (i == numsSize - 1) {
            break;
        } else {
            printf(",");
        }
    }
    printf("]\n");
}
*/
/* Return -1 on not found, > 0 on found */
int findNumberIndex(num_t *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid = left + (right - left) / 2;
    while (left < right && nums[mid].val != target) {
        if (nums[mid].val < target) {
            left = mid + 1;
        } else if (nums[mid].val > target) {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    if (nums[mid].val == target) {
        return mid;
    }
    return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i;
    int find;
    num_t ns[numsSize];
    *returnSize = 2;

    int *idxs = malloc(sizeof(int) * 2);

    for (i = 0; i < numsSize; i++) {
        ns[i].val = nums[i];
        ns[i].idx = i;
    }
    qsort(ns, numsSize, sizeof(num_t), numberCompare);

    for (i = 0; i < numsSize; i++) {
        find = findNumberIndex(ns + i + 1, numsSize - i - 1, target - ns[i].val);
        if (find != -1) {
            idxs[0] = ns[i].idx;
            idxs[1] = ns[find + 1 + i].idx;
            return idxs;
        }
    }
    return idxs;
}
/*
int main(int argc, int argv[])
{
    int returnSize;
    int *returns;
    int nums[] = {3, 2, 4};
    int target = 6;
    returns = twoSum(nums, sizeof(nums) / sizeof(int), target, &returnSize);
    printArr(returns, returnSize);
    return 0;
}
*/

// @lc code=end

