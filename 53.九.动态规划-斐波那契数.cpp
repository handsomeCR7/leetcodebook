#include<iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int a = 0;
        int b = 1;
        int temp;
        for (int i = 2; i <= n; i++) {
            temp = b;
            b = (a + b) % 1000000007;
            a = temp;
        }
        return b;
    }
};

int main() {
    int n = 2;
    Solution s;
    cout << s.fib(n) << endl;
    system("pause");
    return 0;
}