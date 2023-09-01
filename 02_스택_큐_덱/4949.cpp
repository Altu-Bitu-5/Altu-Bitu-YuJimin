#include <iostream> // 입출력 헤더 파일
#include <string> // 문자열 기능 헤더 파일
#include <stack> // 스택 기능 헤더 파일

// std namespace 사용 선언
using namespace std;

// 괄호가 균형을 이루었는지 확인하는 함수
bool isBalanced(string input) {
    // 괄호 저장 스택 생성
    stack<char> s;
    // 문자열의 각 문자에 대해 반복문 실행
    for(int i = 0; i < input.length(); i++) {
        // i 번째 문자열을 ch 변수에 넣음
        char ch = input[i];
        // ch 변수를 기반으로 switch 처리
        switch(ch) {
            // 여는 괄호인 경우
            case '(': case '[':
                // 스택 s에 무조건 push
                s.push(ch);
                // case 빠져나가기
                break;
            // 닫는 괄호인 경우
            case ')':
                // 스택이 비어 있거나, 가장 위에 있는 괄호가 '(' 가 아닌 경우
                if(s.empty() || s.top() != '(') {
                    // false 반환
                    return false;
                }
                // if 조건이 아닌 경우
                // 스택 가장 위의 괄호를 pop
                s.pop();
                // case 빠져나가기
                break;
            // 닫는 대괄호인 경우
            case ']':
                // 스택이 비어 있거나, 가장 위에 있는 괄호가 '[' 가 아닌 경우
                if(s.empty() || s.top() != '[') {
                    // false 반환
                    return false;
                }
                // if 조건이 아닌 경우
                // 스택 가장 위의 괄호를 pop
                s.pop();
                // case 빠져나가기
                break;
        }
    }
    // 스택이 비어 있는 경우 -> 괄호 균형 O -> true 반환
    // 스택이 비어 있지 않은 경우 -> 괄호 균형 X -> false 반환
    return s.empty();
}

// main 함수 정의
int main() {
    // 입력
    // 입력받는 문자열 input 선언
    string input;

    // 무한 루프 시작
    while(true) {
        // 문자열을  입력받아 input에 저장
        getline(cin, input);
        // 입력이 . 인 경우
        if(input == ".") {
            // 반복문 종료
            break;
        }

        // 연산, 출력
        // isBalanced 함수 호출하여 괄호 균형 검사
        // 괄호 균형 O
        if(isBalanced(input)) {
            // yes 입력
            cout << "yes\n";
        }
        // 괄호 균형 X
        else {
            // no 입력
            cout << "no\n";
        }
    }
    // 프로그램 종료
    return 0;
}