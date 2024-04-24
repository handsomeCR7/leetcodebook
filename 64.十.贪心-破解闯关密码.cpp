#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string crackPassword(vector<int>& password) {
        vector<string> str;
        string res;
        for (int i = 0; i < password.size(); i++) {
            str.push_back(to_string(password[i]));
        }
        sort(str.begin(), str.end(), [](string& x, string& y) {return x + y < y + x; });
        for (int i = 0; i < str.size(); i++) {
            res.append(str[i]);
        }
        return res;
    }
};

int main() {
    vector<int> password = { 15, 8, 7 };
    Solution s;
    s.crackPassword(password);
    system("pause");
    return 0;
}