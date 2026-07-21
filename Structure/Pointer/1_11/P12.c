#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int score;
} Student;

int main() {
    Student *p_student = (Student *)malloc(sizeof(Student));
    strcpy(p_student->name,"이승은");
    p_student->score = 90;

    printf("%d, %s", p_student->score, p_student->name);
    free(p_student);
    return 0;
}