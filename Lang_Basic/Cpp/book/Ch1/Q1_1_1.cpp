#include <iostream>
using namespace std;

int main()
{
    int count = 1;
    int num, result;

    result = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << count << "번째 정수 입력: ";
        cin >> num;
        count++;
        result += num;
    }
    cout << "합계: " << result << endl;
}