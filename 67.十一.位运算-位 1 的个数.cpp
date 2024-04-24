#include<iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0; 
        while (n != 0) {
            res += n & 00000000000000000000000000000001;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    uint32_t n = 11;
    Solution s;
    cout << s.hammingWeight(n) << endl;
    system("pause");
    return 0;
}
