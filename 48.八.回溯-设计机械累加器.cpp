#include<iostream>
using namespace std;

class Solution {
public:
    int mechanicalAccumulator(int target) {
        if (target == 1) {
			return 1;
		}
        return target + mechanicalAccumulator(target - 1);
    }
};

int main() {
    int target = 7;
    Solution s;
    cout << s.mechanicalAccumulator(target) << endl;
    system("pause");
    return 0;
}
