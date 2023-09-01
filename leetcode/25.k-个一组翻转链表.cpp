#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for (int i = 0;i < k;++i) {
            if (cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for (int i = 0;i < k;++i) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
// @lc code=end

