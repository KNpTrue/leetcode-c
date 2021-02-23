/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

#include <stdlib.h>

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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
#if 0
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
#else
    struct ListNode *h, *t;
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    if (l1->val < l2->val) {
        h = l1;
        l1 = l1->next;
    } else {
        h = l2;
        l2 = l2->next;
    }

    t = h;

    while (1) {
        if (l1 == NULL) {
            t->next = l2;
            break;
        }
        if (l2 == NULL) {
            t->next = l1;
            break;
        }
        if (l1->val < l2->val) {
            t->next = l1;
            l1 = l1->next;
        } else {
            t->next = l2;
            l2 = l2->next;
        }
        t = t->next;
    }
    return h;
#endif
}
// @lc code=end

