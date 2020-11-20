/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start

#include <stdbool.h>

bool isPalindrome(int x){
#if SOLUTION_1
    char array[10];
    int n = 0;

    if (x < 0 ||(x % 10 == 0 && x != 0)) {
        return false;
    }
    do {
        array[n++] = x % 10;
        x /= 10;
    } while (x);
    for (int i = 0; i < n / 2; i++) {
        if (array[i] != array[n - 1 - i]) {
            return false;
        }
    }
    return true;
#else
    if (x < 0 ||(x % 10 == 0 && x != 0)) {
        return false;
    }
    int r;
    while (x > r) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r == x || x == r / 10;
#endif
}
// @lc code=end

