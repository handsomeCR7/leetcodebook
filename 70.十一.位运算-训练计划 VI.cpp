#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trainingPlan(vector<int>& actions) {
        int Q1 = 0, Q0 = 0;
        int t;
        for (int action : actions) {
            t = (~Q1) & Q0 & action | Q1 & (~Q0) & (~action);
            Q0 = (~Q1) & (~Q0) & action | (~Q1) & Q0 & (~action);
            Q1 = t;  
        }
        return Q0;
    }
};

int main() {
    vector<int> action = { 5, 7, 5, 5 };
    Solution s;
    cout << s.trainingPlan(action) << endl;
    system("pause");
    return 0;
}