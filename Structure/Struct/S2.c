#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
} Person;

int main()
{
    Person people[3];
    Person man;
    Person *ptr = &man;

    for (int i = 0; i < 3; i++) {
        printf("name : ");
        fgets(people[i].name, sizeof(people[i].name), stdin);
         people[i].name[strcspn(people[i].name, "\n")] = 0;

        printf("age : ");
        scanf("%d", &people[i].age);
        getchar(); //입력 버퍼 정리
    }

    for (int i = 0; i < 3; i++) {
        printf("%s\n", people[i].name);
        printf("%d\n", people[i].age);
    }

    strcpy(man.name, "work");
    man.age = 40;

    printf("%d %d", (*ptr).age, ptr->age);

    return 0;
}