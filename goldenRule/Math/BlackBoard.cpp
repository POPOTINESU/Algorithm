#include <iostream>
using namespace std;

int main()
{
    long long N, A[100009];
    char T[100009];
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> T[i] >> A[i];

    long long Answer = 0;
    for (int i = 1; i <= N; i++)
    {
        if (T[i] == '+')
            Answer += A[i];
        if (T[i] == '-')
            Answer -= A[i];
        if (T[i] == '*')
            Answer *= A[i];

        // 引き算で答えが0未満になった場合
        // 10000を足したとして10000で割るから関係ない
        if (Answer < 0)
            Answer += 10000;

        Answer %= 10000;
        cout << Answer << endl;
    }

    return 0;
}