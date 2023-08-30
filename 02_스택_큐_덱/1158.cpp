# include <iostream>
# include <queue>

using namespace std;

queue<int> sol(int n, int k){
    queue<int> answer;
    queue<int> circle;
    
    // 사람들 queue에 넣기
    for(int i=1; i<=n; i++){
        circle.push(i);
    }
    
    while(circle.size() > 0) {
        for (int i=1; i<k; i++) {
            // 앞 사람 뒤로 보내기
            circle.push(circle.front());
            circle.pop();
        }
        // k 번째 사람 추가하고 queue 에서 제거
        answer.push(circle.front());
        circle.pop();
    }
    return answer;
}

int main() {
    // 입력
    int n, k;
    cin >> n >> k;
    // 연산
    queue<int> ans = sol(n, k);
    // 출력
    cout << "<";
    while(ans.size() > 1){
        cout << ans.front();
        ans.pop();
        cout << ", ";
    }
    cout << ans.front() << ">";
    ans.pop();
    
    return 0;
}