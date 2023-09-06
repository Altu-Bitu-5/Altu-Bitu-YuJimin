#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 입력
    int n, k;
    cin >> n >> k;
    
    // vector 생성, 초기화
    vector<char> wheel(n, '?');

    // 화살표 위치
    int arrow= 0;
    
    for(int i=0; i<k; i++) {
        
        // 입력
        int num;
        char alphabet;
        cin >> num >> alphabet;
        
        // 화살표 위치 계산
        arrow = (arrow + n - num) % n;
        
        // 화살표 위치 업데이트
        if (wheel[arrow] != '?' && wheel[arrow] != alphabet) {
            cout << "!\n";
            return 0;
        }
        else {
            wheel[arrow] = alphabet;
        }
    }
    
    // 현재 위치에 다른 문자가 있는 경우 -> ! 출력
    for(int i=0; i< n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if (wheel[i] != '?' && wheel[i] == wheel[j]) {
                cout << "!\n";
                return 0;
            }
        }
    }
    
    // 출력
    for (int i = 0; i < n; i++) {
        cout << wheel[arrow];
        arrow = (arrow + 1) % n;
    }
    cout << '\n';
    
    return 0;
}