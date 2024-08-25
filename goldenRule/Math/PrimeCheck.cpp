#include <iostream>
using namespace std;

bool isPrime(int x)
{
    // 素数かどうかを判定する
    // √x　まで繰り返せば素数かどうかを判定することができる
    // よって、
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int Q, X[10009];
    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> X[i];

    // 出力
    for (int i = 1; i <= Q; i++)
    {
        bool Answer = isPrime(X[i]);
        if (Answer == true)
            cout << "Yes" << endl;
        if (Answer == false)
            cout << "No" << endl;
    }

    return 0;
}