#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    bool verifyTreeOrder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }
private:
    bool recur(vector<int>& postorder, int left, int right) {
        // 终止迭代，开始回溯的条件
        if (left >= right)
        {
            return true;
        }

        // 当前树的根节点为当前区间的右端
        int root = postorder[right];

        // 找出[left,right]中第一个大于root的元素位置。以此为界限，在此位置左边的元素为root的左子树（已经通过下面的遍历确定了）；在此位置的右侧的元素[m+1,right-1]应该都得大于root
        int i = left;
        while(postorder[i] < root)
        {
            i++;
        }

        int m = i;

        while (postorder[i] > root)
        {
            i++;
        }

        return i == right && recur(postorder, left, m - 1) && recur(postorder, m, right - 1);

    }
};

int main42() {
    vector<int>postorder = { 1,2,5,10,6,9,4,3 };
    Solution s;
    bool res = s.verifyTreeOrder(postorder);
    cout << res << endl;

    system("pause");
    return 0;
}