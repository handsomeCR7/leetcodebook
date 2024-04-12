#include <iostream>
using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int zhengfu = 1;    // 正
        int i = 0;
        // 去掉前面空格
        while (str[i] == ' ')
        {
            i++;
        }

        // 看有没有负号，判断正负
        if (str[i] == '-')
        {
            zhengfu = -1;
            i++;
        }
        else if (str[i] == '+')
        {
            i++;
        }
        // 判断数前是不是有无用0
        while (str[i] == '0')
        {
            i++;
        }
        while (str[i] >= '0' && str[i] <= '9')
        {

            if ( (res > (pow(2, 31) - 8) / 10 || (res >= (pow(2, 31) - 8) / 10 && str[i] - '0'>=7)) && zhengfu == 1)
            {
                return pow(2, 31) - 1;
            }
            if ( (res > (pow(2, 31) - 8) / 10 || (res >= (pow(2, 31) - 8) / 10 && str[i] - '0' >= 8) ) && zhengfu == -1)
            {
                return -pow(2, 31);
            }
            res = 10 * res + (str[i] - '0');
            i++;

        }
        return res * zhengfu;
        
    }
};

int main16() {
    string str = "2147483646";
    Solution solution;
    int res = solution.myAtoi(str);
    cout << res << endl;

    system("pause");
    return 0;
}