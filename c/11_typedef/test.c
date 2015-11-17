#include <stdio.h>
#include <string.h>
#include <malloc.h>
struct student{
    char name[20];
    int age;
};
int main(int argc, char *argv[])
{
    typedef struct student *stu;
    struct student stu1 = {
        "xiaoming", 10,      
    };
    struct student stu2 = {
        "daming", 12,      
    };
    stu p_stu = (stu)malloc(10 * sizeof(struct student));
    stu *pp_stu;
    memcpy(p_stu, &stu1, sizeof(struct student));
    memcpy(p_stu+1, &stu2, sizeof(struct student));
    pp_stu = &p_stu;
    printf("name = %s, age = %d\n", p_stu->name, p_stu->age);
    printf("name = %s, age = %d\n", p_stu[1].name, p_stu[1].age);
    printf("name = %s, age = %d\n", pp_stu[0][1].name, pp_stu[0][1].age);
    return 0;
}
