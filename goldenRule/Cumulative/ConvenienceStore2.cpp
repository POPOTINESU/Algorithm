#include <iostream>
using namespace std;

int main(){
    int T, N, L[500000], R[500000], Time[500000], Answer[500000];

    // 入力
    cin >> T >> N;
    for(int i = 0; i < N; i++) cin >> L[i] >> R[i];

    // 前時間比を求める
    for(int i = 0; i < N; i++){
        Time[L[i]] += 1;
        Time[R[i]] -= 1;
    }

    // 累積和を求める
    Answer[0] =  Time[0];

    for(int i = 1; i <= T; i++) Answer[i] = Answer[i-1] + Time[i];

    // 出力
    for(int i = 0; i < T; i++) cout << Answer[i] << endl;
    return 0;
}