#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    int stockManagement(vector<int>& stock) {
        int i = 0;
        int j = stock.size()-1;
        
        for (int i = 0; i < j; i++)
        {
            if (stock[i] > stock[i+1])
            {
                return stock[i + 1];
            }
        }
        return stock[0];
    }
};

int main41() {
    vector<int>stock = { 1,3,1,1,1};
    Solution s;
    int res = s.stockManagement(stock);
    cout << res << endl;

    system("pause");
    return 0;
}