#include <stdio.h>

int count_char(char *parr);

int main(){
    char arr[] = "can you guess how many letters it is?";
    char in_arr[100];
    // char *parr = arr;

    printf("%d 글자 맞지? ㅋㅋ 쉽네~ \n", count_char(arr));

    printf("100자 이내로 입력해봐");
    scanf("%s", in_arr);
    printf("%d 글자 맞지? ㅋㅋ 쉽네~ \n", count_char(in_arr));

    return 0;
}

int count_char(char *parr){
    int count = 0;
    while(parr[count]){
        count++;
    }

    return count;
}