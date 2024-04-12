#include <iostream>
using namespace std;
#include <stack>

class CQueue {
public:
    stack<int>A;
    stack<int>B;
    CQueue() { }

    void appendTail(int value) {
        A.push(value);
    }

    int deleteHead() {
        int res = -1;
        if (!B.empty()) // B有元素
        {
            res = B.top();
            B.pop();
            return res;
        }
        else if (A.empty())  // B空了，A没空，则转移A元素到B中
        {
            return res;
        }
        while (!A.empty())
        {
            res = A.top();
            A.pop();
            B.push(res);
        }
        res = B.top();
        B.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

