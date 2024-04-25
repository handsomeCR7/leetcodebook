#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int inventoryManagement(vector<int>& stock) {
        unordered_map<int, int> m;
        for (int i = 0; i < stock.size(); i++) {
            if (m.find(stock[i]) == m.end()) {
                m[stock[i]] = 1;
            }
            else {
                m[stock[i]]++;
            }
            if (m[stock[i]] > stock.size() / 2) {
                return stock[i];
            }
        }
        return 0;
    }
};

int main() {
    vector<int> stock = { 6, 1, 3, 1, 1, 1 };
    Solution s;
    cout << s.inventoryManagement(stock) << endl;
    system("pause");
    return 0;
}