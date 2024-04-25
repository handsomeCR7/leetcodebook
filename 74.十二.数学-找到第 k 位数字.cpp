#include<iostream>
using namespace std;

class Solution {
public:
    int findKthNumber(int k) {
        int digit = 1;
        long start = 1;
        long count = 9;
        while (k > count) {
            k -= count;
            digit++;
            start *= 10;
            count = 9 * start * digit;
        }
        int num = k / digit;//经历了num个
        int n = k % digit;
        if (n == 0) {
            return (start + num - 1) % 10;
        }
        num = start + num;
        int b = num / (pow(10, digit - n));
        return b % 10;
    }
};

int main() {
    int k = 10;
    Solution s;
    cout << s.findKthNumber(k) << endl;
    system("pause");
    return 0;
}