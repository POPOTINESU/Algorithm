#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009], P[100009], Q[100009];
int D, L[100009], R[100009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> D;
	for (int d = 1; d <= D; d++) cin >> L[d] >> R[d];

    // それぞれの方向から求めた最大値を格納する
    P[1] = A[1];
    for(int i = 2; i<= N; i++ ){
        P[i] = max(P[i-1], A[i]);
    }

    Q[N] = A[N];
    for(int i = N - 1; i >= 1; i --){
        Q[i] = max(Q[i+1], A[i]);
    }

    // L[i]より前の最大値、R[i]より後の最大値をから最大値を求める
    for(int d = 1; d <= D; d++){
        cout << max(P[L[d] -1], Q[R[d] +1]) << endl;
    }

	return 0;
}


// このプログラムだと、計算量的にも間に合わない

// int N,A[109];
// int D,L[100009], R[100009]; 
// int main(){
//     //  入力
//     cin >> N;
//     // Aには何人部屋か記載が入る
//     for(int n = 1; n <= N; n++) cin >> A[n];

//     cin >> D;
//     for(int d=1; d<=D; d++) cin >> L[d] >> R[d];


//     int Answer[1000] = {0};

//     for(int d=1; d<=D; d++){
//         int maxNum = 0;
//         for(int n=1; n<=N; n++){
//             if(L[d]<=n && n <= R[d]){
//                 continue;
//             }
//             if(maxNum < A[n]) {
//                 Answer[d] = A[n];
//                 maxNum = A[n];
//             }
//         }
//     }
//     for(int i = 1; i <= D; i++){
//         cout << Answer[i] << endl;
//     }


//     return 0;
// }