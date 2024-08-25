#include <iostream>
using namespace std;

int main()
{
    int N, A, B;
    bool dp[100009];

    cin >> N >> A >> B;

    for (int stone = 0; stone <= N; stone++)
    {
        // ゲームの終わりから考えていく

        // 相手の手が負けの手だった場合
        if (stone >= A && dp[stone - A] == false)
            dp[stone] = true;
        if (stone >= B && dp[stone - B] == false)
            dp[stone] = true;

        else
            dp[stone] = false;
    }

    if (dp[N] == true)
        cout << "First" << endl;
    else
        cout << "Second" << endl;

    return 0;
}