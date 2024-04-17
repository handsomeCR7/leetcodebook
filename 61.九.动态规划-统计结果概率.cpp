#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<double> statisticsProbability(int num) {
        // 从一开始到最后产生的所有数的个数，最后要舍弃前面num个数
        vector<double> res(6, 1.0 / 6.0);
        // 掷骰子
        for (int i = 2; i <= num; i++) {
            // 暂存此轮结果，以防改变原数据
            vector<double> dp(5 * i + 1, 0);
            // 以上一轮筛出的为底
            for (int j = 0; j < res.size(); j++) {
                for (int k = 0; k < 6; k++) {
                    dp[j + k] += res[j] * 1.0 / 6.0;
                }
            }
            res = dp;
        }
        return res;
    }
};

int main() {
    int num = 3;
    Solution s;
    vector<double> res = s.statisticsProbability(num);
    for (auto res1 : res) {
        cout << res1 << endl;
    }
    system("pause");
    return 0;
}