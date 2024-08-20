#include <iostream>
using namespace std;

// 最初に解いたとき
// int main(){
//     int N;
//     cin >> N;

//     // 2進数を文字列で表現する
//     string binaryString = "";
//     for(int i = 0; i < 10; i++){
//         // あまりを文字列に追加
//         int mod = N % 2;
//         binaryString = to_string(mod) + binaryString;

//         // 一桁ずらす
//         N /= 2;
//     }

//     cout << binaryString << endl;
// }

// 回答例
int main(){
    int N;
    cin >> N;

    // 上の桁から順番に、2進法に変換した値を求める
    for(int x = 9; x >= 0; x--){
        int div = (1 << x);
        cout << N / div % 2;
    }
    cout << endl;
    return 0;
}