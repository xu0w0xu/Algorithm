#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        int lengthA = 0, lengthB = 0;
        //获取两个链表的长度
        ListNode *pA = headA, *pB = headB;
        while(pA != nullptr) {
            lengthA++;
            pA = pA->next;
        }
        while(pB != nullptr) {
            lengthB++;
            pB = pB->next;
        }
        //将两个链表的长度对齐
        pA = headA, pB = headB;
        if(lengthA > lengthB) {
            for(int i = 0; i < lengthA - lengthB; i++) {
                pA = pA->next;
            }
        } else {
            for(int i = 0; i < lengthB - lengthA; i++) {
                pB = pB->next;
            }
        }
        //开始遍历
        while(pA != nullptr && pB != nullptr) {
            if(pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }
};
// @lc code=end

