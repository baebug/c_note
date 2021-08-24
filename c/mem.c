/*
memcpy
메모리의 특정한 부분으로부터 얼마까지의 부분을 다른 메모리 영역으로 복사해준다.
문자열 복사를 전문으로 하는 strcpy가 있지만 memcpy도 나쁘지않다.
개행문자 들어갈 공간 마련해줘야해서 len+1
*/

/*
memmove
I love chewing C hahahahahaha 의 결과가 나온다.
str + 17부터 6개의 문자를 str + 23 위치에 옮김(복사)
메모리 공간이 겹쳐도 된다는 장점이 있다.
*/

/*
memcmp
두 메모리 공간을 서로 비교하는 함수
세번째 인자로 받은 정수만큼(즉, 원하는 만큼) 비교 후, 같다면 0을 리턴한다.
    if (memcmp(arr, arr2, 5) == 0) >> '5개의 원소'가 아니라 5바이트만큼 비교한다.
    전체를 비교하고싶다면 sizeof(int) * 5 를 세번째 인자로 넣어줘야 함.
*/


#include <stdio.h>
#include <string.h>

int main(){
    int arr[10] = {1, 2, 3, 4, 5};
    int arr2[10] = {1, 2, 3, 4, 5};

    if (memcmp(arr, arr2, 5) == 0){
        printf("arr 와 arr2 는 일치! \n");
    } else {
        printf("arr 와 arr2 는 불일치! \n");
    }

    /*
    memmove

    char str[50] = "I love chewing C hahaha";

    printf("%s \n", str);
    printf("memmove 이후 \n");
    memmove(str + 23, str + 17, 6);
    printf("%s \n", str);
    */

    /*
    memcpy

    char str[50] = "I love chewing C hahaha";
    char str2[50];
    char str3[50];

    memcpy(str2, str, strlen(str) + 1);
    memcpy(str3, "hello", 6);

    printf("%s \n", str);
    printf("%s \n", str2);
    printf("%s \n", str3);
    */
    return 0;
}