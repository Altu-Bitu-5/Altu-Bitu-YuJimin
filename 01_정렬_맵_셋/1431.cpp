#include <iostream>
#include <algorithm>

using namespace std;

int getSum(string serial) {
    int totalSum = 0;
    // serial num 에서 숫자를 추출하여 합 구하기
    for (char c : serial) {
        if (isdigit(c)) {
            // '0' 으로 0의 아스키 값을 빼서 숫자 값을 얻는다.
            // 숫자가 문자로 되어 있으므로, 숫자로 변환 가능
            totalSum += c - '0';
        }
    }
    return totalSum;
}

bool sort_guitar(string &a, string &b) {
    // 길이가 다른 경우
    // 정렬1 : 짧은 순서대로 정렬
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    
    // 길이가 같은 경우
    // 정렬2 : 숫자 합이 작은 순서대로 정렬
    else if (a.length() == b.length()) {
        int sum_a = getSum(a);
        int sum_b = getSum(b);
        if (sum_a != sum_b) {
            return sum_a < sum_b;
        }
        
        // 정렬3 : 사전 순서대로 정렬
        return a < b;
    }

    return false;
}

int main() {
    int num;
    cin >> num;
    
    string serial_num[50];
    for(int i=0; i<num; i++) {
        cin >> serial_num[i];
    }
    
    sort(serial_num, serial_num + num, sort_guitar);
    for(int i=0; i<num; i++) {
        cout << serial_num[i] << "\n";
    }
    
    return 0;
}
