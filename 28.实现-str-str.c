/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 */

// @lc code=start

#include <string.h>

int strStr(char * haystack, char * needle){
    if (!needle || !(*needle)) {
        return 0;
    }
    if (!haystack || !(*haystack)) {
        return -1;
    }
    /* SUNDAY */
    int idx = 0;
    int nl = strlen(needle);
    int hl = strlen(haystack);

    if (nl > hl) {
        return -1;
    }

    int limit = hl - nl;
    int step_tab[256];
    int step;

    memset(step_tab, -1, sizeof(step_tab));
    /* generate hash table */
    for (int i = 0; i < nl; i++) {
        step_tab[(unsigned char)needle[i]] = nl - i;
    }

    do {
        for (int i = 0; i < nl; i++) {
            if (haystack[idx + i] != needle[i]) {
                break;
            } else {
                if (i == nl - 1) {
                    return idx;
                }
            }
        }

        step = step_tab[haystack[idx + nl]];
        idx = step != -1 ? idx + step : idx + nl;
    } while (idx <= limit);

    return -1;
}
// @lc code=end

