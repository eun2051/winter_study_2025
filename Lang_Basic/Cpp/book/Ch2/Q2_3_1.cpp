#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct __Point
{
    int xPos;
    int yPos;
} Point;

Point &PntAdder(const Point &p1, const Point &p2)
{
    Point *pptr = new Point;
    pptr->xPos = p1.xPos + p2.xPos;
    pptr->yPos = p1.yPos + p2.yPos;
    return *pptr;
}

int main()
{
    Point *ptr1 = new Point;
    ptr1->xPos = 10;
    ptr1->yPos = 20;

    Point *ptr2 = new Point;
    ptr2->xPos = 30;
    ptr2->yPos = 40;

    Point &result = PntAdder(*ptr1, *ptr2);

    cout << "ptr1: [" << ptr1->xPos << ", " << ptr1->yPos << "]" << endl;
    cout << "ptr2: [" << ptr2->xPos << ", " << ptr2->yPos << "]" << endl;
    cout << "Result: [" << result.xPos << ", " << result.yPos << "]" << endl;
    
    delete ptr1;
    delete ptr2;
    delete &result;

    return 0;
}

// Point &PntAdder(const Point &p1, const Point &p2)
// {
//     return (&p1 + &p2);
// }

// int main()
// {
//     const int xpos = 10;
//     const int ypos = 20;

//     const Point &ptr1 = xpos;
//     const Point &ptr2 = ypos;
//     &PntAdder(ptr1, ptr2);
//     cout << "ptr1: " << ptr1 << endl;
//     cout << "ptr2: " << ptr2 << endl;

// }