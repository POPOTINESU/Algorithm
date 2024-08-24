#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int itemQuantity, weightLimit;
    cin >> itemQuantity >> weightLimit;

    vector<int> weightArray(itemQuantity + 1);
    vector<int> valueArray(itemQuantity + 1);
    vector<vector<long long>> valueDp(itemQuantity + 1, vector<long long>(weightLimit + 1, 0));

    for (int i = 1; i <= itemQuantity; i++) {
        cin >> weightArray[i] >> valueArray[i];
    }

    // ナップサックDP
    for (int i = 1; i <= itemQuantity; i++)
    {
        for (int w = 1; w <= weightLimit; w++)
        {
            if (w < weightArray[i])
            {
                valueDp[i][w] = valueDp[i - 1][w];
            }
            else
            {
                valueDp[i][w] = max(valueDp[i - 1][w], valueDp[i - 1][w - weightArray[i]] + valueArray[i]);
            }
        }
    }

    // 最大価値を出力
    cout << valueDp[itemQuantity][weightLimit] << endl;

    return 0;
}