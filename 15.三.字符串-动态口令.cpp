#include <iostream>
using namespace std;


//class Solution {
//public:
//    string dynamicPassword(string password, int target) {
//        for (int i = 0; i < target; i++)
//        {
//            password.push_back(password[i]);
//        }
//        return password.substr(target, password.size() - target);
//    }
//};
class Solution {
public:
    string dynamicPassword(string password, int target) {
        reverse(password.begin(), password.begin() + target);
        reverse(password.begin() + target, password.end());
        reverse(password.begin(), password.end());
        return password;
    }
};


int main15() {
    string password = "s3cur1tyC0d3";
    Solution solution;
    string res = solution.dynamicPassword(password, 4);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    cout << endl;

    system("pause");
    return 0;
}