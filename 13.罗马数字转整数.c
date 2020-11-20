/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 */

// @lc code=start

int romanToInt(char * s){
    int num = 0;
    char before = '\0';

    for (;*s != '\0'; s++) {
        switch (*s) {
        case 'I':
            num++;
            break;
        case 'V':
            if (before == 'I') {
                num += 3;
            } else {
                num += 5;
            }
            break;
        case 'X':
            if (before == 'I') {
                num += 8;
            } else {
                num += 10;
            }
            break;
        case 'L':
            if (before == 'X') {
                num += 30;
            } else {
                num += 50;
            }
            break;
        case 'C':
            if (before == 'X') {
                num += 80;
            } else {
                num += 100;
            }
            break;
        case 'D':
            if (before == 'C') {
                num += 300;
            } else {
                num += 500;
            }
            break;
        case 'M':
            if (before == 'C') {
                num += 800;
            } else {
                num += 1000;
            }
            break;
        default:
            break;
        }
        before = *s;
    }
    return num;
}
// @lc code=end

