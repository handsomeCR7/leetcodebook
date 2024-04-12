#include <iostream>
using namespace std;
#include <list>
#include <vector>

class MedianFinder {
public:
    /** initialize your data structure here. */
    list<int>A;
    vector<double>zhong;
    int i = 0;
    list<int>::iterator j = A.begin();
    list<int>::iterator k = A.begin();
    MedianFinder() {
        zhong.resize(2);
    }

    void addNum(int num) {
        j = A.begin();
        for (j; j != A.end(); j++) {
            if (num < *j)
            {
                A.insert(j, num);
                break;
            }
        }
        
        if (A.empty() || j == A.end())
        {
            A.emplace_back(num);
        }
        if (A.size() == 1)
        {
            zhong[0] = num;
        }
        else if (A.size() % 2 == 0) // 偶
        {
            k = A.begin();
            for (int t = 0; t < A.size() / 2 - 1; t++, k++)
            {
            }
            zhong[0] = *k;
            k++;
            zhong[1] = *k;
        }
        else  // 奇
        {
            k = A.begin();
            for (int t = 0; t < A.size() / 2 ; t++, k++)
            {
            }
            zhong[0] = *k;
        }
    }

    double findMedian() {
        if (A.size() == 1)
        {
            return zhong[0];
        }
        else if (A.size() % 2 == 0)   // 偶
        {
            return (zhong[0] + zhong[1]) / 2;
        }
        else
        {
            return zhong[0];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main23() {
    MedianFinder* obj = new MedianFinder();
    /*obj->addNum(-1);
    obj->findMedian();
    obj->addNum(-2);
    obj->findMedian();
    obj->addNum(-3);
    obj->findMedian();
    obj->addNum(-4);
    obj->findMedian();
    obj->addNum(-5);
    obj->findMedian();*/
    obj->addNum(6);
    obj->findMedian();
    obj->addNum(10);
    obj->findMedian();
    obj->addNum(2);
    obj->findMedian();
    obj->addNum(6);
    obj->findMedian();
    obj->addNum(5);
    obj->findMedian();
    obj->addNum(0);
    obj->findMedian();
    obj->addNum(6);
    obj->findMedian();
    obj->addNum(3);
    obj->findMedian();
    obj->addNum(1);
    obj->findMedian();
    obj->addNum(0);
    obj->findMedian();
    obj->addNum(0);
    obj->findMedian();



    system("pause");
    return 0;
}