#include <iostream>
using namespace std;

int H, W, N;
int A[100009], B[100009], C[100009], D[100009];
int Z[1509][1509], X[1509][1509];
int main(){
    // 入力
    cin >> H >> W >>N;
    for(int i = 1; i<=N; i++) cin >> A[i] >>B[i] >> C[i] >> D[i];
    

    // 各日の計算
    for(int i = 1; i <= N; i++){
        X[A[i]][B[i]] += 1;
        X[A[i]][D[i]+1] -= 1;
        X[C[i]+1][B[i]] -= 1;
        X[C[i]+1][D[i]+1] += 1;
    }

    // Z配列の初期化
    for(int i=0; i<= H; i++){
        for(int j=0; j<=W; j++){
            Z[i][j] = 0;
        }
    }

    for(int y=1; y<=H; y++){
        for(int x=1; x<=W; x++) Z[y][x] = Z[y][x -1] + X[y][x];
    }

    for(int x=1; x<=W; x++){
        for(int y=1; y<=H; y++) Z[y][x] = Z[y-1][x] + Z[y][x];
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(j >= 2) cout << " ";
            cout << Z[i][j];
        }
        cout << endl;
    }

    return 0;
}