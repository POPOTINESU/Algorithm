#include <iostream>
using namespace std;

int N, K;
int A[10000009], int B[10000009], int C[10000009], int D[10000009];
int R[10000009], L[10000009];

int main()
{
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];
    for (int i = 1; i <= N; i++)
        cin >> C[i];
    for (int i = 1; i <= N; i++)
        cin >> D[i];

    for (int i = 1; i <= N; i++)
    {
        // 2つの配列にして計算しやすくする
        R[i] = A[i] + B[i];
        L[i] = C[i] + D[i];
    }

    for (int i = 1; i <= N; i++)
    {
        // 差分を求める
        int diff = K - R[i];

        // 昇順ソートして、2分木で該当するものがあるか検証
        sort(L, L + N);
        int center;
        int start = 1;
        int end = N;
        while (start <= end)
        {
            center = (start + end) / 2;

            if (center < L[diff])
                start = center + 1;
            if (center == L[diff])
                return "Yes";
            if (center > L[diff])
                end = center - 1;
        }
    }

    cout << "No" << endl;
    return 0;
}