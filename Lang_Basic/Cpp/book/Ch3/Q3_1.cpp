#include <iostream>
using namespace std;

struct Point
{
    int xPos;
    int yPos;

    // 점의 좌표 이동
    void MovePos(int x, int y)
    {
        xPos += x;
        yPos += y;
    }
    // 점의 좌표 증가
    void AddPoint(const Point &pos)
    {
        xPos += pos.xPos;
        yPos += pos.yPos;
    }
    // 현재 x, y 좌표 정보 출력
    void ShowPosition()
    {
        cout << xPos << ", " << yPos << endl;
    }
};

int main()
{
    Point pos1 = {12, 4};
    Point pos2 = {20, 30};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition();

    pos1.AddPoint(pos2);
    pos1.ShowPosition();
    return 0;
}