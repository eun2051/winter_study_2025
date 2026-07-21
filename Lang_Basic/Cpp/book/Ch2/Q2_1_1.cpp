#include <iostream>
using namespace std;

void plus_(int &n);
void change_(int &n);

int main()
{
    int num = 10;

    plus_(num);
    cout << num << endl;
    change_(num);
    cout << num;

}

void plus_(int &n)
{
    n += 1;
}

void change_(int &n)
{
    n *= -1;
}