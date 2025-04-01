#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    int day, month, year;
};      // 세미콜론을 붙여야 한다.

bool younger(const Student& a, const Student& b) {
    // const는 상수 변수로서 값을 변경할 수 없게끔 하고,
    // Student& a와 Student& b는 Student 객체를 참조로 받게끔 한다.
    if(a.year != b.year) return a.year > b.year;
    if(a.month != b.month) return a.month > b.month;
    return a.day > b.day;
    // a의 생년월일이 b의 생년월일보다 늦으면(a > b) bool 값이 1이고,
    //                          이르면(a < b) bool 값이 0이다.
}

int main() {
    int n;      
    cin >> n;   // 학생 수를 입력받는다.

    vector<Student> students(n);    // n명의 학생 정보를 담는 벡터

    for (int i = 0; i < n; i++)     // 학생 정보를 입력받는다.
    {
        cin >> students[i].name >> students[i]. day >> students[i].month >> students[i].year;
    }
    
    Student youngest = students[0];
    Student oldest = students[0];   // 제일 어린 학생과 제일 늙은 학생을 우선 첫 원소로 설정한다.

    for (int i = 1; i < n; ++i) {   // 두 번째 학생부터 비교를 시작한다.
        if(younger(students[i], youngest)) {
            youngest = students[i];
            // students[i]의 생년월일이 youngest의 생년월일보다 늦으면
            //  bool(younger) 값이 1이 되고, students[i]의 값을 youngest에 대입해
            // 제일 어린 학생이 students[i]가 되게끔 한다.
        }
        if(!younger(students[i], oldest)) {
            oldest = students[i];
            // students[i]의 생년원일이 oldest의 생년월일보다 이르면
            // bool(younger) 값이 0이 되지만 !가 붙어 다시 1이 되고,
            // students[i]의 값을 oldest에 대입해
            // 제일 늙은 학생이 students[i]가 되게끔 한다.
        }
    }
        cout << youngest.name << endl;
        cout << oldest.name << endl;
}