#include <iostream>
using namespace std;

// 初期の自分の回答
// int main(){

//     int N;
//     int X;

//     cin >> N >> X;

//     int A;
//     bool flag = false;
//     for(int i = 0; i < N; i ++){
//         cin >> A;

//         if(X == A){
//             flag = true;
//         }
//     }

//     if(flag){
//         cout << "Yes" << endl;
//     }else{
//         cout << "No" << endl;
//     }
//     return 0;
// }

int N, X, A[109];
bool Answer = false;

int main(){
    // 入力値を受け取る
    cin >> N >> X;
    for(int i = 1; i <= N; i++) cin >> A[i];

    // xが配列に含まれているか検証する
    for(int i = 1; i <= N; i++){
        if (A[i] == X) Answer = true;
    }

    // 出力
    if(Answer == true) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
