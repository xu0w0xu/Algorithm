#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head; 
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next; 
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

