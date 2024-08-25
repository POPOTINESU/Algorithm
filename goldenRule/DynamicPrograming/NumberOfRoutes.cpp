#include <iostream>
using namespace std;

long long H, W;
char C[39][39];
long long dp[39][39];

int main()
{

    cin >> H >> W;

    for (int h = 1; h <= H; h++)
    {
        for (int w = 1; w <= W; w++)
        {
            cin >> C[h][w];
        }
    }

    // 動的配列の実装
    // 組み合わせは、dp[h-1][w]とdp[h][w-1]を足したもの

    for (int h = 1; h <= H; h++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (h == 1 && w == 1)
            {
                // スタート位置
                dp[h][w] = 1;
            }

            else
            {
                // 初期化
                dp[h][w] = 0;
                // 縦移動
                if (h >= 2 && C[h - 1][w] == '.')
                    dp[h][w] += dp[h - 1][w];
                if (w >= 2 && C[h][w - 1] == '.')
                    dp[h][w] += dp[h][w - 1];
            }
        }
    }

    cout << dp[H][W] << endl;

    return 0;
}