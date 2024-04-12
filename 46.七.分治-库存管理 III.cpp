#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        return quickSort(stock, 0, stock.size() - 1, cnt);
    }
private:
    vector<int> quickSort(vector<int>& stock, int left, int right,int cnt) {
        int i = left;
        int j = right;
        while (i < j)
        {
            while (i < j && stock[j] >= stock[left])
            {
                j--;
            }
            while (i < j && stock[i] <= stock[left])
            {
                i++;
            }
            swap(stock[i], stock[j]);
        }
        swap(stock[left], stock[i]);

        if (i > cnt)
        {
            return quickSort(stock, left, i - 1, cnt);
        }
        else if (i < cnt)
        {
            return quickSort(stock, i + 1, right, cnt);
        }
        vector<int>res;
        res.assign(stock.begin(), stock.begin() + cnt);
        return res;
        
    }

};

int main46() {
    vector<int>stock = { 0, 0, 0, 2, 0, 5 };
    int cnt = 0;
    Solution s;
    for (int i : s.inventoryManagement(stock, cnt))
    {
        cout << i << ' ';
    }
    cout << endl;

    system("pause");
    return 0;
}