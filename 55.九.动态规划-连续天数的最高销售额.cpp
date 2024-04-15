#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSales(vector<int>& sales) {
        int dp = sales[0];
        // 以第i天为截止的
        for (int i = 1; i < sales.size(); i++) {
            if (dp <= 0) {
                dp = sales[i];
            }
            else {
                dp = dp + sales[i];
            }

            if (dp > sales[0]) {
                sales[0] = dp;
            }
        }
        return sales[0];
    }
};

int main() {
    vector<int> sales = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    Solution s;
    cout << s.maxSales(sales) << endl;
    system("pause");
    return 0;
}