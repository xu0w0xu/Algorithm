#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

 // @lc code=start
class MyStack {
    queue<int> q;
    int top_elem = 0;
public:

    void push(int x) {
        q.push(x);
        top_elem = x;
    }

    int pop() {
        int size = q.size();
        while(size > 2){
            q.push(q.front());
            q.pop();
            size--;
        }
        top_elem = q.front();
        q.push(q.front());
        q.pop();
        int tmp = q.front();
        q.pop();
        return tmp;
    }

    int top() {
        return top_elem;
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 // @lc code=end

