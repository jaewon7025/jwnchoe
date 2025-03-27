#include <iostream>

using namespace std;

int main(){
    int n, p, C, maxprice;
    string N, maxname;
    maxprice = -1;     // 첫 번째 선수의 가격보다도 무조건 낮을 수를 넣는다.

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> p;
        for(int j = 0; j < p; j++) {
            cin >> C >> N;
            if(maxprice < C) {      // 비교 대상의 가격이 maxprice보다 높으면 가격과 이름을 갱신한다.
                maxprice = C;
                maxname = N;
            }
        }
        cout << maxname << '\n';
        maxprice = -1;  // 이전 테스트 케이스에서 높아진 maxprice를 초기화한다.
    }
    return 0;
}