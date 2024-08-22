#include <iostream>
using namespace std;

int N, L[100009], R[100009];
int D, B[100009];
int Answer[100009];

int main() {
	// 入力
	cin >> D >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

	// 前日比に加算
    for(int i = 1; i <= N; i++){
        B[L[i]] += 1;
        B[R[i] + 1] -=1;
    }

    // 累積和
    Answer[0] = 0;
    for(int i = 1; i <= D; i++) Answer[i] = Answer[i -1] + B[i];
    //　1日ごとの出席者を出力
    for(int i =1; i<= D; i++) cout << Answer[i] << endl;
	return 0;
}