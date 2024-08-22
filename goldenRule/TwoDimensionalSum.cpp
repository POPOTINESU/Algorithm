#include <iostream>
using namespace std;

// 各列の累積和を求めた配列を、Square配列に入れて格納する
int H, W, Q;
int X[1500][1500], Z[1500][1500];
int A[100000], B[100000], C[100000], D[100000];

int main(){
    // 入力
    cin >> H >> W;
    // 配列Xに数字を格納
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> X[i][j];
        }
    }

    // Z配列を初期化する
    // index out of rangeの対策
    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            Z[i][j] = 0;
        }
    }

    // 縦横それぞれの追跡話を取る

    // 横の累積和
    for (int y = 1; y <= H; y++)
    {
        for (int x = 1; x <= W; x++)
        {
            Z[y][x] = Z[y][x - 1] + X[y][x];
        }
    }

    // 縦の累積和
    for (int x = 1; x <= W; x++)
    {
        for (int y = 1; y <= H; y++)
        {
            Z[y][x] = Z[y - 1][x] + Z[y][x];
        }
    }

    // 質問の入力
    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    // 回答
    for (int i = 1; i <= Q; i++)
    {
        cout << Z[C[i]][D[i]] + Z[A[i] - 1][B[i] - 1] - Z[C[i]][B[i] - 1] - Z[A[i] - 1][D[i]] << endl;
    }

    return 0;
}
