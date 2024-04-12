#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int res = 0;
    int reversePairs(vector<int>& record) {
        mergeSort(record, 0, record.size() - 1);
        return res;
    }
private:
    // 合并
    void merge(vector<int>& record, int left, int mid, int right) {
        vector<int>temp;
        int i = left;
        int j = mid + 1;
        while (i <= mid && j <= right)
        {
            if (record[i] <= record[j])
            {
                temp.push_back(record[i]);
                i++;
            }
            else
            {
                temp.push_back(record[j]);
                res += mid - i + 1;
                j++;
            }
        }
        while (i <= mid)
        {
            temp.push_back(record[i]);
            i++;
        }
        while (j <= right)
        {
            temp.push_back(record[j]);
            j++;
        }

        for (int t = 0; t < temp.size(); t++)
        {
            record[t + left] = temp[t];
        }

    }

    // 归并排序
    void mergeSort(vector<int>& record, int left, int right) {
        if (left >= right)
        {
            return;
        }

        int mid = (left + right) / 2;
        // 递归划分
        mergeSort(record, left, mid);
        mergeSort(record, mid + 1, right);
        // 合并
        merge(record, left, mid, right);
    }
};

int main47() {
    vector<int>record = {  };
    Solution s;
    cout << s.reversePairs(record) << endl;

    system("pause");
    return 0;
}