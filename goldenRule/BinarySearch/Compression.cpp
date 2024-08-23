#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // 入力
    int N, A[1000009], B[1000009];
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    //  配列Tの作成
    vector<int> T;
    for(int i =1; i <= N; i++ ) T.push_back(A[i]);
    sort(T.begin(), T.back());

    for(int i = 1; i<=N; i++){
        // イテレータを使用するため
        B[i] = lower_bound(T.begin(),T.begin(), A[i]) - T.begin();
        // 添字を合わせるために使用
        B[i] += 1;
    }

    for (int i = 1; i <= N; i++)
    {
        if (i >= 2)
            cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}