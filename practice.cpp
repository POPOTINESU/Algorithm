#include <iostream>
#include <algorithm>
using namespace std;

// nは、2以上200,000である
static const int MAX = 200000;

int main()
{
    // 最大値200000の配列の作成
    int R[MAX], n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> R[i];

    // 利益が-である可能性を考慮して小さい数を格納する
    int maxv = -200000000;
    // 最小値の初期値は配列の一番目の要素を指定する
    int minv = R[0];

    for (int i=0; i < n; i++)
    {
        maxv = max(maxv, R[i] - minv);
        minv = min(minv, R[i]);
    }

    cout << maxv << endl;
    return 0;
}