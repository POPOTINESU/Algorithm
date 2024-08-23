#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int A[100000], B[100000];
    int dp[100000];

    cin >> N;
    
    for (int i = 2; i <= N; i++)
        cin >> A[i];
    for (int i = 3; i <= N; i++)
        cin >> B[i];

    // 動的計画法で最短経路を求める

    // 一番目の部屋は、移動する必要がない
    dp[1] = 0;
    // 二番目の部屋は、確実にA[i]になる
    dp[2] = A[2];
    // 3番目の部屋から求める
    for (int i = 3; i <= N; i++)
    {
        // 1つ前の部屋と2つ前の部屋からの経路で最短を選ぶ
        dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);
    }

    cout << dp[N] << endl;

    return 0;
}
