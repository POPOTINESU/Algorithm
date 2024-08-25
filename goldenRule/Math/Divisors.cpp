#include <iostream>
using namespace std;

int main()
{
    long long N;
    cin >> N;

    long long three = (N / 3);
    long long five = (N / 5);
    long long fifteen = (N / 15);

    cout << three + five + fifteen << endl;

    return 0;
}