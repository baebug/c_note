/* human.c */
/*
printf를 위한 <stdio.h>
Human 구조체를 사용하므로 "human.h"
copy_str 함수를 사용하므로 "str.h" 가 아니라 <string.h>
*/
#include <stdio.h>
#include <string.h>
#include "human.h"

struct Human Create_Human(char *name, int age, int gender){
    struct Human human;

    human.age = age;
    human.gender = gender;
    strcpy(human.name, name);

    return human;
}

int Print_Human(struct Human *human){
    printf("Name : %s \n", human->name);
    printf("age : %d \n", human->age);
    if (human->gender == MALE){
       printf("Gender : Male \n");
    } else if (human->gender == FEMALE){
       printf("Gender : Female \n");
    }

    return 0;
}