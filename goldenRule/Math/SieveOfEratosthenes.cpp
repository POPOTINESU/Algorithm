#include <iostream>
using namespace std;

int Q, X[10009], N = 300000; // X[i]が300000以下なので、それ以下の素数を求める
bool Deleted[300009];        // 整数が除去されているか判断

int main()
{
    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> X[i];
    // 1は判断しないものとする
    for (int i = 2; i <= N; i++)
    {
        Deleted[i] = false;
    }

    // エラトステネスの篩
    // 平方根から
    for (int i = 2; i * i <= N; i++)
    {
        if (Deleted[i] == true)
            continue;
        // 同じ数
        for (int j = i * 2; j <= N; j += i)
            Deleted[i] = true;
    }

    // 出力
    for (int i = 1; i <= Q; i++)
    {
        if (Deleted[X[i]] == false)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}