# include <iostream>
#include <algorithm>
# include <string> 

using namespace std;

// string 을 이용하여 큰 정수 사용
// '0' 을 빼주면 string 을 숫자로 변환 가능
string getSum(string a, string b) {
    // 올림 수 초기화
    int carry = 0;
    string answer;
    // a, b 문자열의 길이
    int len_a = a.length();
    int len_b = b.length();
    // 긴 문자열 선택
    int len_max = max(len_a, len_b);
    // for문 돌면서 계산
    // 문자열의 길이 또는 캐리가 남아있으면 계속 반복
    for (int i=0; i<len_max || carry > 0; i++){
        // 첫번째 수 a 확인
        int first_num;
        // len_a 가 더 큰 경우
        // -> 자릿수를 가져옴
        if (i < len_a){
            first_num = a[len_a - 1 - i] - '0';
        // len_a 가 더 작은 경우
        // -> 그냥 0으로 설정
        } else {
            first_num = 0;
        }
        // 두번째 수 b 확인
        int second_num;
        if (i < len_b){
            second_num = b[len_b - 1 - i] - '0';
        } else {
            second_num = 0;
        }
        // 두 수 a, b 를 합함
        int sum = first_num + second_num + carry;
        carry = sum / 10;
        sum = sum % 10;
        
        answer += to_string(sum);
    }
    // 문자열을 뒤집어서 출력
    string result;
    for(int i = answer.length() - 1; i>=0; i--){
        result += answer[i];
    }
    return result;
}

int main() {
    // 입력
    string a, b;
    cin >> a >> b;
    // 연산
    string ans = getSum(a, b);
    // 출력
    cout << ans << '\n';
    
    return 0;
}