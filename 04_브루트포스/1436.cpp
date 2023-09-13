#include <iostream>

using namespace std;

int joongmal(int n) {
    
    int check_num = 666;
    int cnt = 0;
    
    // n번째 찾을 때까지 반복
    while (cnt < n) {
        // 검사하는 숫자
        int check = check_num;
        // 6이 연속으로 나타나는 개수
        int six_cnt = 0;

        while (check > 0) {
            // 6인 경우
            if (check % 10 == 6) {
                // 증가
                six_cnt++;
                // 연속된 6이 3개 이상이면 -> cnt 증가
                if (six_cnt >= 3) {
                    cnt++;
                    break;
                }
            } else {
                six_cnt = 0;
            }
            check /= 10;
        }
    
        // 다음 숫자
        if (cnt < n) {
            check_num++;
        }
    }
    
    return check_num;
}

int main() {
    
    // 입력
    int n;
    cin >> n;
    
    // 출력
    cout << joongmal(n);

    return 0;
}
