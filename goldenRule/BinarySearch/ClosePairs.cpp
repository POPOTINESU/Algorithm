#include <iostream>
using namespace std;

int N, K;
int A[100009],R[100009];

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    // 尺取り法
    for (int i = 1; i <= N - 1; i++)
    {
        // スタート位置を決める
        if (i == 1)
            R[i] = 1;
        else
            R[i] = R[i - 1];

        // ギリギリまで増やしていく
        while (R[i] < N && A[R[i] + 1] - A[i] <= K)
        {
            R[i] += 1;
        }
    }

    long long Answer = 0;
    for (int i = 1; i <= N - 1; i++)
        Answer += (R[i] - i);
    cout << Answer << endl;

    return 0;
}