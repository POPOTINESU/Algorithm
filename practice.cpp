#include <iostream>
using namespace std;

int main()
{
    int A, B;

    cin >> A >> B;

    bool isDivisor = false;
    // 100の約数かどうかなので、線形探索で計算する
    for (int i = A; i <= B; i++)
    {
        if (100 % i == 0)
        {
            isDivisor = true;
            break;
        }
    }

    if (isDivisor)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}