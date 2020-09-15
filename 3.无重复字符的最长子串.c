/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){
    int i, start = 0, count, max = 0;
    int index[128] = {0};
    for (i = 0; s[i] != '\0'; i++) {
        if (index[s[i]] > start) { //重复
            count = i - start;
            if (count > max) {
                max = count;
            }
            start = index[s[i]];
        }
        index[s[i]] = i + 1;
    }
    count = i - start;
    return count > max ? count : max;
}
// @lc code=end

