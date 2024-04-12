#include <iostream>
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
	vector<int> statisticalResult(vector<int>& arrayA) {
		if (arrayA.size() == 0)
		{
			return {};
		}

		vector<int>arrayB(arrayA.size());
		arrayB[0] = 1;
		/*for (int i = 0; i < arrayA.size(); i++)
		{
			chengji = chengji * arrayA[i];
		}
		for (int i = 0; i < arrayA.size(); i++)
		{
			if (arrayA[i] == 0)
			{
				int chengji1 = 1;
				for (int j = 0; j < arrayA.size(); j++)
				{
					if (j == i)
					{
						continue;
					}
					chengji1 = chengji1 * arrayA[j];
				}
				arrayB.push_back(chengji1);
				continue;
			}
			arrayB.push_back(chengji / arrayA[i]);
		}*/

		int temp = 1;
		// 主对角线上的数都为1
		for (int i = 1; i < arrayA.size(); i++) // 下标i前面的乘积，下三角
		{
			arrayB[i] = arrayB[i - 1] * arrayA[i - 1];
		}
		for (int i = arrayA.size() - 2; i >= 0; i--)    // 下标i后面的乘积，上三角
		{
			temp = temp * arrayA[i + 1];
			arrayB[i] = arrayB[i] * temp;

		}


		return arrayB;
	}
};


int main3() {
	Solution solution;
	vector<int>arrayA;

	int num;
	while (cin >> num)
	{
		arrayA.push_back(num);
		if (cin.get() == '\n')
		{
			break;
		}
	}

	vector<int>res = solution.statisticalResult(arrayA);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}



	system("pause");
	return 0;
}