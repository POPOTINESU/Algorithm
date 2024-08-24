#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int A[100], B[100];
    int dp[100];
    vector<int> Answer;

    cin >> N;
    for (int i = 2; i <= N; i++)
        cin >> A[i];
    for (int i = 3; i <= N; i++)
        cin >> B[i];

    // 動的計画法
    dp[1] = 0;
    dp[2] = A[2];
    for (int i = 3; i <= N; i++)
        dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);

    // Nがゴールの部屋になる
    int Place = N;
    while (true)
    {
        // ゴールからスタートに向かう経路
        Answer.push_back(Place);
        if (Place == 1)
            break;

        if (dp[Place - 2] + B[Place] == dp[Place])
            Place = Place - 2;
        else
            Place = Place - 1;
    }

    // ゴールからのルートなので、逆順にする
    reverse(Answer.begin(), Answer.end());

    cout << Answer.size() << endl;
    for (int i = 0; i < Answer.size(); i++)
    {
        if (i >= 1)
            cout << " ";
        cout << Answer[i];
    }
    cout << endl;

    return 0;
}