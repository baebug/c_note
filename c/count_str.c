#include <stdio.h>

int count_str(char *pstr);

int main(){
    char str[] = {"c language is very hard!!!"};
    char *pstr = str;
    
    printf("이 문자열의 길이는 %d글자가 맞습니다. \n", count_str(pstr));

    return 0;
}
/* 
scanf("%c", &char)
scanf("%s", array) --> 왜 Why?
배열 이름을 써주는거 자체가 &array[0]의 주소값을 전달해주는거기 때문이다.
*/

int count_str(char *pstr){
    int count = 0;

    while(*pstr){
        count++;
        pstr++;
    }
    printf("%d 글자 아님? \n", count);

    return count;
}
