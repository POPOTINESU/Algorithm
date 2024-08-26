#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int A_PizzaCost, B_PizzaCost, AB_PizzaCost, A_Number, B_Number;
    cin >> A_PizzaCost >> B_PizzaCost >> AB_PizzaCost >> A_Number >> B_Number;

    // 考えられる方法を計算し、比較して答えを求める
    int case_1 = A_PizzaCost * A_Number + B_PizzaCost * B_Number;
    int case_2 = AB_PizzaCost * 2 * max(A_Number, B_Number);

    int minNumber = min(A_Number, B_Number);
    int case_3 = AB_PizzaCost * 2 * minNumber + A_PizzaCost * (A_Number - minNumber) + B_PizzaCost * (B_Number - minNumber);



    cout << min({case_1,case_2, case_3})<< endl;

    return 0;
}