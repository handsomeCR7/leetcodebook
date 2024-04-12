#include <iostream>
using namespace std;
#include <deque>

class Checkout {
public:
    deque<int>A;
    deque<int>max;
    Checkout() {
    }

    int get_max() {
        if (max.empty())  return -1;
        return max.front();
    }

    void add(int value) {
        A.emplace_back(value);
        if (A.size() == 1)
        {
            max.emplace_back(value);
        }
        while (!max.empty() && value >= max.back())
        {
            max.pop_back();
        }
        max.emplace_back(value);
    }

    int remove() {
        if (A.empty())  return -1;
        if (A.front() == max.front())
        {
            max.pop_front();
        }
        int res = A.front();
        A.pop_front();
        return res;
    }
};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */