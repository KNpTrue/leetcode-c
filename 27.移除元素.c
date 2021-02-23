/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] 移除元素
 */

// @lc code=start


int removeElement(int* nums, int numsSize, int val){
#if 0
    int retSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[retSize] = nums[i];
            retSize++;
        }
    }
    return retSize;
#else
    int i = 0;
    while (i < numsSize) {
        if (nums[i] == val) {
            nums[i] = nums[numsSize - 1];
            numsSize--;
        } else {
            i++;
        }
    }
    return numsSize;
#endif
}
// @lc code=end

