#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sockCollocation(vector<int>& sockets) {
        int n = 0;
        int m = 1;
        int x = 0;
        int y = 0;
        for (int i = 0; i < sockets.size(); i++) {
            n ^= sockets[i];
        }
        while ((n & m) == 0) {
            m <<= 1;
        }
        for (int i = 0; i < sockets.size(); i++) {
            if (sockets[i] & m) {
                x ^= sockets[i];
            }
            else {
                y ^= sockets[i];
            }
        }
        return { x,y };
    }
};

int main() {
    vector<int> sockets = { 4, 5, 2, 4, 6, 6 };
    Solution s;
    s.sockCollocation(sockets);
    system("pause");
    return 0;
}