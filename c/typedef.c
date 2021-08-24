#include <stdio.h>

struct HUMAN
{
    int age;
    int height;
    int weight;
    int gender;
};

/* struct HUMAN 을 Human으로 사용하겠다! (기존의 것도 유효) */
typedef struct HUMAN Human;
int Print_Status(Human human);
int main(){
    Human Adam = {31, 182, 75, 0};
    Human Eve = {27, 166, 48, 1};

    Print_Status(Adam);
    Print_Status(Eve);

    return 0;
}

int Print_Status(Human human){
    if (human.gender == 0){
        printf("MALE \n");
    } else {
        printf("FEMALE \n");
    }

    return 0;
}

/*
[(int, int)를 인자로 받는 int형 포인터]의 이름을 Padd라고 한다.

typedef int (*Padd)(int, int)
> int (*ptr)(int, int) = add
> Padd ptr = add
*/

/*
[원소 10개를 갖는 int형 배열]의 이름을 Arrays라고 한다.

typedef int Arrays[10]
> int arr[10];
> Arrays arr;
*/
