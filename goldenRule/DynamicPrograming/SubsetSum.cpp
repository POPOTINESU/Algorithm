#include <iostream>
using namespace std;

int main()
{
    // 入力を受け取る
    int N, S;
    cin >> N >> S;
    int A[N];
    bool dp[60][10000];
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    // 動的計画法(i=0)
    dp[0][0] = true;
    for (int i = 1; i <= S; i++)
        dp[0][i] = false;

    // (i>=1)
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            if (j < A[i])
            {
                if (dp[i - 1][j] == true)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else if (j >= A[i])
            {
                if (dp[i - 1][j] == true || dp[i - 1][j - A[i]] == true)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }
    }

    // 0列目は、0しかありえないので、0だけがtrue
    dp[0][0] = true;
    for (int i = 1; i <= N; i++)
        dp[0][i] = false;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            if (dp[i - 1][j] == true)
            {
                // 1行目の同じ列がtrueならtrue
                dp[i][j] == true;
            }
            else if (j >= A[i] && dp[i - 1][j - A[i]] == true)
            {
                // 前列の、
                dp[i][j] = true;
            }
        }
    }

    // 出力
    if (dp[N][S] == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}