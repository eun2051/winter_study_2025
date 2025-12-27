#include <iostream>
using namespace std;

int id, money;
char name[100];

void make_account();
void input_();
void output_();
void print();

int main()
{
    int num;

    while (1) {
        cout << "-----Menu-----" << endl;
        cout << "1. 계좌개설" << "\n" << "2. 입 금" << "\n" << "3. 출 금";
        cout << "\n" << "4. 계좌정보 전체 출력" << "\n" << "5. 프로그램 종료" << endl;
        cout << "선택: ";
        cin >> num;

        switch (num) {
            case 1:
                make_account();
                break;
            case 2:
                input_();
                break;
            case 3:
                output_();
                break;
            case 4:
                print();
                break;
            case 5:
                cout << "프로그램을 종료합니다." << endl;
                return 0;
        }
    }
    return 0;

}

void make_account()
{
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> money;
}

void input_()
{
    int plus;

    cout << "[입 금]" << endl;
    cout << "계좌ID: " << id << endl;
    cout << "입금액: ";
    cin >> plus;

    money += plus;
    cout << "입금완료";
}

void output_()
{
    int minus;

    cout << "[출 금]" << endl;
    cout << "계좌ID: " << id << endl;
    cout << "출금액: ";
    cin >> minus;

    if (money - minus > 0) {
        money -= minus;
        cout << "출금 완료";
    } else {
        cout << "출금 불가";
    }
}

void print()
{
    cout << "계좌ID: " << id << endl;
    cout << "이름: " << name << endl;
    cout << "입금액: " << money << endl;
}