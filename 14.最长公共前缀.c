/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <stdlib.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    if (!strsSize) {
        return "";
    }
    int i, j;
    size_t str0_len = strlen(strs[0]);
    for (i = 0; i < str0_len; i++) {
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}
// @lc code=end

