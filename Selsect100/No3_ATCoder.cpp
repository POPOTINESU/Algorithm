#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 変数の設定
    string S;
    string ACGT = "ACGT";

    // 入力
    cin >> S;

    int count = 0;
    int maxCount = 0;

    // Sを一文字ずつ検証し、ACGTの中にあるか検証する
    for (char c : S)
    {
        if (ACGT.find(c) != string::npos)
        {
            // ACGTに含まれている場合、カウントを増やす
            count++;
        }
        else
        {
            // ACGTに含まれていない場合、maxCountを更新し、カウントをリセット
            maxCount = max(maxCount, count);
            count = 0;
        }
    }

    // 最後の部分をチェックする
    maxCount = max(maxCount, count);

    cout << maxCount << endl;
    return 0;
}