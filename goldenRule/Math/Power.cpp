#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    long long div = 1000000007;

    long long Answer = 1;

    cin >> a >> b;

    // 条件的に30回までしかループしない
    for (int i = 1; i < 30; i++)
    {
        // 2進数で表した時に、1の時つまり、あまりが1の時のみ
        // 繰り返し2条法に使われる
        if ((b / i) % 2 == 1)
        {
            Answer = (Answer * a) % div;
        }
        a = (a * a) % div;
    }

    cout << Answer << endl;

    return 0;
}