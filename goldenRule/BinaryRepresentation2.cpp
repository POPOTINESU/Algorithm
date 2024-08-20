#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //2進法で与えられたものを、10進法に変換する

    int N;
    cin >> N;
    int result = 0;

    for(int i = 0; N != 0; i++){
        // 一番下の桁から10進法に変換する
        int mod = N % 10;
        result += mod * pow(2,i);

        // 1桁ずらす
        N /= 10;
    }
    cout << result << endl;
    return 0;
}