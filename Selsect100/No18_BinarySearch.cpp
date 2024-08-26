#include <iostream>
using namespace std;

int main()
{
    int SortedArrayNum, SortedArray[100009];
    int TargetArrayNum, TargetArray[50009];

    cin >> SortedArrayNum;
    for (int i = 1; i <= SortedArrayNum; i++)
        cin >> SortedArray[i];

    cin >> TargetArrayNum;
    for (int j = 1; j <= TargetArrayNum; j++)
        cin >> TargetArray[j];

    // SortedArrayの中にTargetArrayの要素の個数を求める

    int answer = 0;
    for (int i = 1; i <= TargetArrayNum; i++)
    {
        // 2分探索の初期値
        int start = 1;
        int end = SortedArrayNum;

        // 2分探索
        while (start <= end)
        {
            // 中央値
            int center = (start + end) / 2;

            if (TargetArray[i] < SortedArray[center])
            {
                end = center - 1;
            }
            else if (TargetArray[i] == SortedArray[center])
            {
                answer++;
                break;
            }
            else
            {
                start = center + 1;
            }
        }
    }

    cout << answer << endl;
    return 0;
}