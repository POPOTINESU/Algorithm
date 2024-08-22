#include <iostream>
using namespace std;

bool isOneHandledDivisor(int num){
    //100の約数かどうか調べる
    if(100 % num == 0) return true;
    else return false;
}

int main(){
    int A, B;
    cin >> A >> B;

    int count = 0;
    for(int i = A; i <= B; i ++){
        // 100の約数の個数を数える
        if(isOneHandledDivisor(i)) count += 1;
    }

    // 100の役数があればYesを返す
    if(count > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}