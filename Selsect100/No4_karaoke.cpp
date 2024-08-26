#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int Student, SongNumber;
    int ScoreArray[109][109];

    // 入力
    cin >> Student >> SongNumber;

    // 行は生徒の数
    // 列は、曲の種類
    for (int i = 1; i <= Student; i++)
    {
        for (int j = 1; j <= SongNumber; j++)
        {
            cin >> ScoreArray[i][j];
        }
    }

    int maxSum = 0;

    // M曲の中から2曲選ぶ
    for (int i = 1; i <= SongNumber; i++)
    {
        for (int j = i + 1; j <= SongNumber; j++)
        {
            int sum = 0;

            for (int student = 1; student <= Student; student++)
            {
                sum += max(ScoreArray[student][i], ScoreArray[student][j]);
            }

            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum << endl;
    return 0;
}