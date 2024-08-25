#include <iostream>
#include <algorithm>
using namespace std;

int N, P[2009], A[2009];
int dp[2009][2009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i] >> A[i];

	// 動的計画法（LEN は r-l の値）
	dp[1][N] = 0;
    // LENはN-2から始める,
    // LEN=Nの場合、indexをオーバーしてしまう
    // LEN=N-1の場合は、すでに求めたdp[1][N]
    // よってLEN=N-2からスターとする

    // lはN-LENまでループする
    // 4 - 2 = 2
    // l = 1
    // l = 2
    
    // r = 1+2 = 3
    // r = 2+2 = 4
	for (int LEN = N - 2; LEN >= 0; LEN--) {
		for (int l = 1; l <= N - LEN; l++) {
			int r = l + LEN;

			// score1 の値（l-1 番目のブロックを取り除くときの得点）を求める

            // l = 1 r = 3
            // P[0] これは存在しないためスキップする 

            // l= 2 r = 4
            // P[1] = 4
            // 2 <= 4 <= 4条件を満たすので、score1をA[1]=20にする
            // score1=20

            // 外枠ループ
            // LEN=1
            // N-LEN = 4-1 = 3
            // l = 1
            // r = 1+1 = 2

            //とりあえずスキップ
            int score1 = 0;
			if (l <= P[l - 1] && P[l - 1] <= r) score1 = A[l - 1];

			// score2 の値（r+1 番目のブロックを取り除くときの得点）を求める

            // P[3+1] = 1
            // 1<= 1 <= 3条件を満たす
            // score2に,A[3+1] = 10　をプラスする

            // 2 <= P[5] これは存在しないのでパス

            // r+1 = 3
            // P[1,3]
            // 1 <= P[3] = 2 <= 2
            // score2= A[3]=40
			int score2 = 0;
			if (l <= P[r + 1] && P[r + 1] <= r) score2 = A[r + 1];

			// dp[l][r] を求める
            // lが1なのでこれが実行
            // dp[1][3]にdp[1][4]に10を足したものを格納

            // l = 2だから作動しない


            //l=1なので、実行
            // dp[1][2]= dp[1][3] + 40
			if (l == 1) {
				dp[l][r] = dp[l][r + 1] + score2;
			}
            // r = 4 N=4なので、実行
			else if (r == N) {
                // dp[1][4] に20をプラス
                // dp[2][4]=20
				dp[l][r] = dp[l - 1][r] + score1;
			}
			else {
				dp[l][r] = max(dp[l - 1][r] + score1, dp[l][r + 1] + score2);
			}
		}
	}

	// 出力
	int Answer = 0;
	for (int i = 1; i <= N; i++) Answer = max(Answer, dp[i][i]);
	cout << Answer << endl;
	return 0;
}