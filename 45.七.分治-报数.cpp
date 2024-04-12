#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> countNumbers(int cnt) {
        int num = mynum(cnt);
        vector<int>res;
        for (int i = 1; i <= num; i++)
        {
            res.push_back(i);
        }
        return res;
    }
private:
    int mynum(int cnt) {
        int num = 1;
        for (int i = 1; i <= cnt; i++)
        {
            num *= 10;
        }
        return num - 1;
    }
};

int main45() {
    Solution s;
    for (int i : s.countNumbers(1))
    {
        cout << i << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}