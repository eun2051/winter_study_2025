#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point{
    int x;
    int y;
} Point;

typedef struct Person {
    int age;
    char *name;
} Person;

int main()
{
    Point p1_ = {10, 20};
    printf("%d %d\n", p1_.x, p1_.y);

    //얕은 복사 : 실제 데이터가 아니라 주소를 복사하는 것
    Person p1, p2;

    p1.name = (char *)malloc(sizeof(char) * 50);
    p2.name = (char *)malloc(sizeof(char) * 50);
    strcpy(p1.name, "lee");
    p1.age = 23;
    strcpy(p2.name, "Park");
    p2.age = 25;
    
    printf("name : %s, age : %d\n", p1.name, p1.age);
    printf("name : %s, age : %d\n", p2.name, p2.age);
    
    p2 = p1;

    printf("name : %s, age : %d\n", p1.name, p1.age);
    printf("name : %s, age : %d\n", p2.name, p2.age);

    //깊은 복사 : 별도의 메모리 공간에 실제 데이터를 복사
    // 구조체 내의 모든 변수를 일일히 복사해줌
    strcpy(p2.name, p1.name);
    p2.age = p1.age;

    strcpy(p1.name, "p12");

    printf("name : %s, age : %d\n", p1.name, p1.age);
    printf("name : %s, age : %d\n", p2.name, p2.age);
    return 0;
}