#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int i = 0;
        int j = records.size() - 1;
        int m = 0;
        while (i <= j)
        {
            m = (i + j) / 2;
            if (records[m] != m)
            {
                j = m - 1;
            }
            else
            {
                i = m + 1;
            }
        }
        return i;
    }
};

int main39() {
    vector<int>records = {0};

    Solution s;
    int res = s.takeAttendance(records);
    cout << res << endl;
    system("pause");
    return 0;
}