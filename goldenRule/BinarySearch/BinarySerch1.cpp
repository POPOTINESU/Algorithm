#include <iostream>
using namespace std;

int N, X;
int A[100000009];

int binarySerch(int target)
{
    // 2分岐探索を行う

    int start = 1;
    int last = N;

    while (start <= last)
    {
        // 中央値を求める
        int center = (start + last) / 2;

        // 2分木で要素を半分にする
        if (target < A[center])
            last = center - 1;
        else if (target > A[center])
            start = center + 1;

        // 中央値とtargetが一致したindexを返す
        else
            return center;
    }

    return -1;
}

int main()
{

    cin >> N >> X;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    int Answer = binarySerch(X);
    cout << Answer << endl;
    return 0;
}