#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool checkDynasty(vector<int>& places) {
        int max = 0;
        int min = 14;
        int zero = 0;
        int size;
        unordered_set<int> CR;
        for (int i = 0; i < 5; i++) {
            if (places[i] > max && places[i] != 0) {
                max = places[i];
            }
            if (places[i] < min && places[i] != 0) {
                min = places[i];
            }
            if (places[i] == 0) {
                zero++;
            }
            CR.insert(places[i]);
        }
        
        if (zero != 0) {
            size = CR.size() + zero - 1;
        }
        else {
            size = CR.size();
        }

        if (max - min < 5 &&size == 5 && max - min + zero - 1 <= 5) {
            return 1;
        }
        return 0;
            
    }
};

int main() {
    vector<int> places = { 0,6,9,0,7 };
    Solution s;
    cout << s.checkDynasty(places) << endl;
    system("pause");
    return 0;
}