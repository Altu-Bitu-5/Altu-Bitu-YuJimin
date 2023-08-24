// 입출력 라이브러리
#include <iostream>
// C++ STL 라이브러리
#include <set>
// 표준 라이브러리 함수, 객체 사용 선언
using namespace std;

// main 함수
int main()
{
    // 정수형 변수 n, m, cnt 선언
	int n, m, cnt = 0;
	// 문자열 저장을 위한 객체 선언
	set<string> s;
	// 입력받을 문자열 저장
	string input;
	// 입력
	cin >> n >> m;
	// 입력받은 n번 만큼 반복
	while (n--) {
	    // 문자열 입력
		cin >> input;
		// 입력받은 문자열을 set에 원소 추가
		s.insert(input);
	}
	// 연산
	// m번 만큼 반복
	while (m--) {
	    // 연산을 수행할 문자열 입력
		cin >> input;
		// find 함수 사용
		// 입력받은 문자열이 set에 존재하는지 확인
		// 존재하는 경우 -> iterator 반환
		// 존재하지 않는 경우 -> set::end 반환
		if (s.find(input) != s.end()) { 
		    // 존재하는 경우 cnt 값을 증가
			cnt++;
		}
	}
	// 출력
	cout << cnt << '\n';
	// 프로그램 종료
	return 0;
}