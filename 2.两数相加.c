/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head, *cur;
    struct ListNode **t = &head;
    int val;
    int carry = 0;

    while (l1 || l2 || carry) {
        *t = malloc(sizeof(struct ListNode));
        if (!(*t)) {
            goto failed;
        }
        val = 0;
        if (l1) {
            val += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            val += l2->val;
            l2 = l2->next;
        }
        val += carry;
        if (val >= 10) {
            carry = 1;
            val -= 10;
        } else {
            carry = 0;
        }
        (*t)->val = val;
        t = &(*t)->next;
    }
end:
    *t = NULL;
    return head;
failed:
    while (head) {
        cur = head;
        head = head->next;
        free(cur);
    }
    return NULL;
}

// @lc code=end

