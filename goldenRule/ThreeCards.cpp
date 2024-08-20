#include <iostream>
using namespace std;

int main(){
    int N, K, count = 0;
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j<=N; j++){
            int remainder = K - i - j;

            // 正の数でNより上ならOK
            if(remainder > 0 && remainder <= N) count++;
        }
    }
    cout << count << endl;
    return 0;
}