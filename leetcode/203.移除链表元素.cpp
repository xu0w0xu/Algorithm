#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

 // @lc code=start
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode() : val(0), next(nullptr) {}
  *     ListNode(int x) : val(x), next(nullptr) {}
  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
  * };
  */
typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
} ListNode;
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head); // 创建虚拟节点作为头节点
        ListNode* cur = dummy;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next; // 保存要删除的节点
                cur->next = cur->next->next; // 删除节点
                delete temp; // 释放内存
            }
            else {
                cur = cur->next;
            }
        }
        ListNode* newHead = dummy->next; // 获取新的头节点
        delete dummy; // 释放虚拟节点的内存
        return newHead;
    }
};
// @lc code=end

