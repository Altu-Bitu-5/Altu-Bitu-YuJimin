#include <iostream>

using namespace std;

// 최대 공약수 구하는 함수
int gcd(int a, int b) {
    while (b != 0) {
        int num = a % b;
        a = b;
        b = num;
    }
    return a;
}

// main 함수
int main() {
    // 입력
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;

    // 분수 더하기
    int top = a * d + b * c;
    int bottom = b * d;

    // 최대 공약수 구하기
    int gcd_num = gcd(top, bottom);

    // 최대 공약수로 나누어 기약분수 만들기
    top /= gcd_num;
    bottom /= gcd_num;

    cout << top << ' ' << bottom << '\n';

    return 0;
}
