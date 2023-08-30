#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int weight, first_bmr, t, day, bmr, activity;
    
    // 입력
    cin >> weight >> first_bmr >> t;
    cin >> day >> bmr >> activity;
    
    int predict_weight = weight;
    
    // Case1 : 기초대사량 변화 고려 X
    int use_energy = first_bmr + activity;
    
    for (int i = 0; i < day; i++) {
        predict_weight += bmr - use_energy;
    }
    
    if (predict_weight <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << predict_weight << " " << first_bmr << "\n";
    }
    
    // Case2 : 기초대사량 변화 고려 O
    int next_bmr = first_bmr;
    predict_weight = weight;  // 체중 초기화
    
    for (int i = 0; i < day; i++) {
        // 기초대사량 계산
        int use_energy = next_bmr + activity;
        predict_weight += bmr - use_energy;
        
        if (abs(bmr - use_energy) > t) {
            next_bmr += floor((bmr - use_energy) / 2.0);
        }
    }
    
    if (predict_weight <= 0 || next_bmr <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << predict_weight << " " << next_bmr << " ";
        
        if (first_bmr - next_bmr > 0) {
            cout << "YOYO";
        } else {
            cout << "NO";
        }
    }
    
    return 0;
}
