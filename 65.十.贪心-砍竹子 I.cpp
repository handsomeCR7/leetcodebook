#include<iostream>
using namespace std;

class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len <= 3) {
            return 1 * (bamboo_len - 1);
        }
        int a = bamboo_len / 3;
        int b = bamboo_len % 3;
        if (b == 1) {
            return pow(3, a - 1) * 2 * 2;
        }
        else if (b == 2) {
            return pow(3, a) * 2;
        }
        return pow(3, a);
    }
};

int main() {
    int bamboo_len = 12;
    Solution s;
    cout << s.cuttingBamboo(bamboo_len) << endl;
    system("pause");
    return 0;
}