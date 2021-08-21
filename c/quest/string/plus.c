#include <stdio.h>

int plus_arr(char *parr1, char *parr2, char *parr3);
int print_arr(char *parr);

int main(){
    char arr1[100], arr2[100], result_arr[200];

    printf("첫번째 문자열을 입력하세요. \n");
    scanf("%s", arr1);
    printf("\n");

    printf("두번째 문자열을 입력하세요. \n");
    scanf("%s", arr2);
    printf("\n");

    plus_arr(arr1, arr2, result_arr);

    printf("합쳐진 결과물입니다. \n");
    print_arr(arr1);
    print_arr(arr2);
    print_arr(result_arr);

    return 0;
}

int plus_arr(char *parr1, char *parr2, char *parr3){
    int i, j;
    while(parr1[i]){
        parr3[i] = parr1[i];
        i++;
    }
    while(parr2[j]){
        parr3[i+j] = parr2[j];
        j++;
    }
    /* 마지막에 Null 넣어주기! (detail) */
    parr3[i+j] = '\0';

    return 0;
}

int print_arr(char *parr){
    int i = 0;
    while(parr[i]){
        printf("%c", parr[i]);
        i++;
    }
    printf("\n");

    return 0;
}