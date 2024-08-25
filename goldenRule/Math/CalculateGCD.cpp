#include <iostream>
using namespace std;

int GCD(int L, int R)
{
    // ユークリッド互除法
    while (L >= 1 && R >= 1)
    {
        // 多い方を少ない法で割り、そのあまりで多い方を更新する
        if (L >= R)
        {
            L = L % R;
        }
        else
        {
            R = R % L;
        }
    }
    if (L != 0)
    {
        return L;
    }
    else
    {
        return R;
    }
}

int main()
{
    int A, B;
    cin >> A >> B;
    cout << GCD(A, B) << endl;

    return 0;
}