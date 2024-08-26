#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;

    int Answer = 0;
    // 奇数ループ
    for (int i = 1; i <= N; i += 2)
    {
        int count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if (count == 8)
        {
            Answer++;
        }
    }

    cout << Answer << endl;

    return 0;
}
