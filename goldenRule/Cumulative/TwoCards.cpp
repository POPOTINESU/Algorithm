#include <iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    // N枚のカードを2組保存
    int P[N], Q[N];

    for(int i = 1; i <= N; i ++) cin >> P[i];
    for(int i = 1; i <= N; i ++) cin >> Q[i];

    bool flag = false;
    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= N; j++){
            // 目標値(K)になる数字があるか検証
            if(K - P[i] == Q[j]){
                flag = true;
                break;
            }
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}