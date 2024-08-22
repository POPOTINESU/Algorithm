#include <iostream>
using namespace std;

long long N, K;
long long A[100009];

bool check(long long x)
{
    // 答えがx以下か判定する
    long long sum = 0;
    // xが経過時間
    // A[i]が、プリンターが１枚生成する時間
    for (int i = 1; i <= N; i++)
        sum += x / A[i];
    if (sum >= K)
        return true;
    return false;
}

int main()
{
    // 　入力
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    // 探索範囲の始まりと終わりを定義
    long long Left = 1, Right = 1'000'000'000;

    while (Left < Right)
    {
        // 中央値を求める
        long long Center = (Left + Right) / 2;
        bool Answer = check(Center);
        if (Answer == true)
            Right = Center;
        if (Answer == false)
            Left = Center + 1;
    }

    // Left = Rightなので、それが答え
    cout << Left << endl;

    return 0;
}