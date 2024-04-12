#include <iostream>
using namespace std;


class Solution {
public:
    string pathEncryption(string path) {
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == '.')
            {
                path[i] = ' ';
            }
        }
        return path;
    }
};


int main13() {
    string str = "a.aef.qerf.bb";
    Solution solution;
    string res = solution.pathEncryption(str);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    cout << endl;

    system("pause");
    return 0;
}
