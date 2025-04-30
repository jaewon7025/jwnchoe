#include <iostream>
#include <iomanip>      // setw(n): 출력 필드의 폭을 n칸 확보해주는 함수
                        // setfill('0'): 빈칸을 0으로 채움
using namespace std;

int timetoseconds(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
    // h시간 m분 s초는 (h * 3600 + m * 60 + s)초이다. 
}   // 시간을 초 단위로 환산해주는 함수

void secondstotime(int totalseconds) {
    int h = totalseconds / 3600;
    totalseconds = totalseconds % 3600;
    int m = totalseconds / 60;
    int s = totalseconds % 60;

    cout << setw(2) << setfill('0') << h << ":"
         << setw(2) << setfill('0') << m << ":"
         << setw(2) << setfill('0') << s << endl;
}   // main 함수에서 구한 시간 차이를 형식에 맞게 출력하는 함수

int main() {
    int h1, m1, s1;
    int h2, m2, s2;
    char colon;

    // 현재 시간 입력
    cin >> h1 >> colon >> m1 >> colon >> s1;
    // 임무 시작 시간 입력
    cin >> h2 >> colon >> m2 >> colon >> s2;

    int currenttime = timetoseconds(h1, m1, s1);
    int starttime = timetoseconds(h2, m2, s2);
    int diff = starttime - currenttime; // 시간 차이
    if (diff <= 0) {diff = diff + 24 * 3600;}
    // starttime보다 currenttime이 크거나 starttime이 currenttime과 같아서
    // diff가 0 이하가 되는 경우 diff에 하루만큼의 시간을 초 단위로 더한다.

    secondstotime(diff);
    return 0;
}