/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stdbool.h>

bool isValid(char * s){
    int top = -1;
    int len = strlen(s);
    char cs[len + 1];
    for (; *s != '\0'; s++) {
        switch (*s) {
        case '(':
            cs[++top] = ')';
            break;
        case '{':
            cs[++top] = '}';
            break;
        case '[':
            cs[++top] = ']';
            break;
        case ')':
        case '}':
        case ']':
            if (top == -1) {
                return false;
            }
            if (cs[top--] != *s) {
                return false;
            }
            break;
        default:
            break;
        }
    }
    return top == -1;
}
// @lc code=end

