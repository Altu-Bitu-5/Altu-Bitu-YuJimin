#include <iostream> // 입출력 헤더파일
#include <vector> // 벡터 헤더 파일
#include <algorithm> // 알고리즘 헤더 파일

// std namespace 사용 선언
using namespace std;

// 소수 여부 반환 함수
// 에라토스테네스의 체 이용
vector<bool> getPrimes(int n) {
    // 소수인지 저장하는 벡터 생성, 소수로 초기화
    vector<bool> is_prime(n + 1, true);
    // 0과 1은 소수 아님
    is_prime[0] = is_prime[1] = false;
    // 2부터 n 제곱근까지 for문 반복
    for (int i = 2; i * i <= n; i++) {
        // 소수가 아닌 경우
        if (!is_prime[i]) {
            // 건너 뛰기
            continue;
        }
        // 소수의 배수인 경우
        for (int j = i * i; j <= n; j += i) {
            // 소수가 아님
            is_prime[j] = false;
        }
    }
    // 소수 여부 저장 벡터 반환
    return is_prime;
}

// n = a + b를 만족시키는 a 반환
int goldbach(int n, vector<bool> &is_prime) {
    // 3부터 n/2 까지 홀수 for문 반복
    for (int a = 3; a <= n / 2; a+= 2) {
        // 2보다 큰 짝수 소수는 존재하지 않으므로
        // a = 3부터 탐색해도 a와 b 모두 홀수여야 한다는 조건 만족
        // a와 n-a가 모두 소수인 경우
        if (is_prime[a] && is_prime[n - a]) {
            // a를 반환
            return a;
        }
    }
    // n = a + b를 만족시키는 홀수 소수 a, b가 없는 경우
    // 0 반환
    return 0;
}

// main 함수
int main() {
    // 입력
    // 입력 값을 저장할 벡터 생성
    vector<int> arr;
    // input 변수 생성
    int input;
    // 1을 입력받을 때까지 무한 루프
    while(1) {
        // input 변수에 입력
        cin >> input;
        // 입력받은 값이 0인 경우
        if (input == 0) {
            // 루프 종료
            break;
        }
        // 0이 아닌 경우
        // 벡터에 값을 저장
        arr.push_back(input);
    }

    // 연산
    // 입력에서 최댓값 찾기
    int max_num = *max_element(arr.begin(), arr.end());
    // 최댓값까지의 소수를 계산
    vector<bool> is_prime = getPrimes(max_num);

    // 입력받은 값 하나씩 순회
    for (int i = 0; i < arr.size(); i++) {
        // 골드 바흐 만족하는 수 찾아서 a에 저장
        int a = goldbach(arr[i], is_prime);

        // 출력
        // n = a + b를 만족하는 a, b가 존재하는 경우
        if (a != 0) { 
            // 골드바흐 값 출력
            cout << arr[i] << " = " << a << " + " << arr[i] - a << "\n";
        // 존재하지 않는 경우
        } else {
            // 에러메시지 출력
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    // 정상 종료
    return 0;
}