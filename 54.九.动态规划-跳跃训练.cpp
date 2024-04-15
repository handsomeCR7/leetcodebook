#include<iostream>
using namespace std;

class Solution {
public:
    int trainWays(int num) {
        if (num == 0) {
            return 1;
        }
        if (num <= 2) {
            return num;
        }
        int a = 1;
        int b = 2;
        int temp;
        for (int i = 3; i <= num; i++) {
            temp = b;
            b = (a + b) % 1000000007;
            a = temp;
        }
        return b;
    }
};

int main() {
    int num = 5;
    Solution s;
    cout << s.trainWays(num) << endl;
    system("pause");
    return 0;
}