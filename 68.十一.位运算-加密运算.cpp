#include<iostream>
using namespace std;


class Solution {
public:
    int encryptionCalculate(int dataA, int dataB) {
        while (dataB != 0)
        {
            int c = (unsigned int)(dataA & dataB) << 1;
            dataA ^= dataB;
            dataB = c;
        }
        return dataA;
    }
};

int main() {
    int dataA = 5;
    int dataB = -1;
    Solution s;
    cout << s.encryptionCalculate(dataA, dataB) << endl;
    system("pause");
    return 0;
}