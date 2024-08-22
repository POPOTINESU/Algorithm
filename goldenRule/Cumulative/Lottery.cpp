#include <iostream>
using namespace std;

int main(){
    int N, A, Q, L[100000], R[100000];
    int sum[100000];

    sum[0] = 0;

    // N回くじを引いて累積和を求める
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A;
        sum[i] = sum[i-1] + A;
    }

    // Qの回数を引き、質問を配列に入れる
    cin >> Q;
    for(int i = 1; i <= Q; i++) cin >> L[i] >> R[i];

    
    for(int i = 1; i <= Q; i++){
        // 初期化
        int zero = 0;
        int one = 0;

        // 0と1それぞれの総和を計算
        for(int j = sum[R[i] -1];j <= L[i]; j++ ){
            if(sum[j] == 1) one ++;
            else zero ++;
        }

        // 出力
        if(one > zero) cout << "win" << endl;
        else if(one == zero) cout << "draw" << endl;
        else cout << "lose" << endl;
    }

    return 0;
}