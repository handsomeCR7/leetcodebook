#include <iostream>
using namespace std;
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    stack<int>A;
    stack<int>min;

    void push(int x) {
        A.push(x);
        if (A.size() == 1 || x <= min.top())    // 第一个元素直接压入min，或者小于上一个元素也可以压入min
        {
            min.push(x);
        }
    }

    void pop() {
        if (A.top() == min.top())   // 如果pop的刚好是min，则同时pop A和min，否则只pop A
        {
            min.pop();
        }
        A.pop();
    }

    int top() {
        return A.top();
    }

    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */