#include <iostream>
using namespace std;

int main()
{
    int money = 0;
    int result = 0;

    while (1)
    {
        cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
        cin >> money;
        if (money == -1)
        {
            cout << "프로그램을 종료합니다" << endl;
            break;
        }
        result = 50 + money * 0.12;
        cout << "이번 달 급여: " << result << "만원" << endl;
    }
}