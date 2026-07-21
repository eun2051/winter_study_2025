#include <iostream>
using namespace std;
//처음 생각했던,,,, 가리키는 곳 안에 들어있는 값을 바꾸는 함수
// void SwapPointer(int *ptr1, int *ptr2)
// {
//     int temp = *ptr1;
//     *ptr1 = *ptr2;
//     *ptr2 = temp;
// }

// 가리키는 대상(주소)를 바꾸는 함수
void SwapPointer(int *&ptr1, int *&ptr2)
{
    int *temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}
int main()
{
    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;
    cout << "ptr1: " << ptr1 << endl;
    cout << "ptr2: " << ptr2 << endl;
    SwapPointer(ptr1, ptr2);
    cout << "ptr1: " << ptr1 << endl;
    cout << "ptr2: " << ptr2 << endl;

    return 0;
}