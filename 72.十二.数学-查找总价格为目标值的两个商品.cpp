#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int i = 0;
        int j = price.size() - 1;
        while (i < j) {
            if (price[i] + price[j] < target) {
                i++;
            }
            else if (price[i] + price[j] > target) {
                j--;
            }
            else {
                return { price[i], price[j] };
            }
        }
        return {};
    }
};

int main() {
    vector<int> price = { 3, 9, 12, 15 }; 
    int target = 18;
    Solution s;
    s.twoSum(price, target);
    system("pause");
    return 0;
}