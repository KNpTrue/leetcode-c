/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start


int reverse(int x){
    long src = x;
    long ret = 0;
    do {
        ret = ret * 10 + (src % 10);
        src = src / 10;
    } while (src);
    if (ret != (int)ret) {
        return 0;
    }
    return ret;
}
// @lc code=end

