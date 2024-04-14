#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void dfs(string &state, string &goods, vector<bool>&select, vector<string>&res) {
        if (state.size() == goods.size()) {
            res.push_back(state);
            return;
        }
        unordered_set<char>xiangtongyuansu;//同一轮里不能出现值一样的元素
        for (int i = 0; i < goods.size(); i++) {
            //如果这个元素前几轮没有被选择，且这一轮没有被选择，则可以选择，并标记
            if (select[i] == 0 && xiangtongyuansu.find(goods[i]) == xiangtongyuansu.end()) {
                select[i] = 1;
                xiangtongyuansu.emplace(goods[i]);
                state.push_back(goods[i]);

                dfs(state, goods, select, res);

                select[i] = 0;//清零，为了不影响本层其他兄弟节点的后续选择
                state.pop_back();
            }
        }
    }
    vector<string> goodsOrder(string goods) {
        string state;
        vector<bool>select(goods.size(), 0);//不同轮里不能出现被选择过的元素
        vector<string>res;
        dfs(state, goods, select, res);
        return res;
    }
};

int main() {
    string goods = "aab";
    Solution s;
    vector<string>res = s.goodsOrder(goods);
    for (int i = 0; i < goods.size(); i++) {
        cout << res[i] << endl;
    }
    system("pause");
    return 0;
}