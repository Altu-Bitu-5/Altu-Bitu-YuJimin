#include <iostream>

using namespace std;

int main() {
    
    // 입력
    int m;
    scanf("%d", &m);

    // 비어 있는 공집합 s
    int s = 0;
    // 모든 정수 표현
    int all_num = (1 << 21) - 1;

    while (m--) {
        
        // 수행해야 하는 연산 한 줄씩 입력받기
        string calculate;
        cin >> calculate;

        // all 또는 empty인 경우에는 숫자 입력 X
        int x;
        if (calculate != "all" && calculate != "empty") {
            cin >> x;
        }
        // add: S에 x를 추가
        if (calculate == "add") {
            s |= (1 << x);
        }
        // remove: S에서 x를 제거
        else if (calculate == "remove") {
            s &= ~(1 << x);
        }
        // check:  S에 x가 있으면 1을, 없으면 0
        else if (calculate == "check") {
            int num = (s & (1 << x)) ? 1 : 0;
            cout << num << '\n';
        }
        // toggle: S에 x가 있으면 x를 제거하고, 없으면 x를 추가
        else if (calculate == "toggle") {
            s ^= (1 << x);
        }
        // all : s 전체 집합으로 바꾸기
        else if (calculate == "all") {
            s = all_num;
        }
        // empty : 공집합으로 바꾸기
        else if (calculate == "empty") {
            s = 0;
        }
    }

    return 0;
}
