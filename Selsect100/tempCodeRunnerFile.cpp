#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 1~nの重複無しの数を3つ選びその合計がxとなる組み合わせ

    // 入力値の量が分からないので、vectorを使用
    vector<int> Number, Target;

    while (true)
    {
        int n, x;
        cin >> n >> x;

        if (n == 0 && x == 0)
            break;

        Number.push_back(n);
        Target.push_back(x);
    }

    for (int i = 1; i <= Number.size(); i++)
    {
        int count = 0;
        for (int j = 1; j <= Number[i]; j++)
        {
            for (int k = j + 1; k <= Number[i]; k++)
            {
                // 差分を求めて条件に合致するか調べる
                int diff = Target[i] - j - k;
                if (k < diff && diff <= Number[i])
                    count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}