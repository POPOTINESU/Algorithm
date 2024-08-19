#include <iostream>
using namespace std;

int main(){
    // 入力
    int N;
    cin >> N;

    int A[N];
    for(int i = 1; i<=N; i++) cin >> A[i];
    bool flag = false;
    for(int i = 1; i<=N; i++){
        for(int j = i+1; j<=N; j++){
            for(int k = j+1; k<=N; k++){
                if(1000 == A[i]+A[j]+A[k]) flag = true;
            }
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}