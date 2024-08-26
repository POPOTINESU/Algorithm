#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int answer = 0;

    // 奇数のループ
    for(int oddNum = 1; oddNum <= N; oddNum += 2){
        // oddNumの約数をcountする
        int count = 0;
        for(int num = 1; num <= oddNum; num ++){
            if (oddNum % num == 0){
                count ++;
            }
        }
        if(count == 8){
            answer ++;
        }
    }

    cout << answer << endl;
    return 0;
}