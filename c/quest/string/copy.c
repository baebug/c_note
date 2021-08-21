#include <stdio.h>

int copy_arr(char *parr1, char *parr2);
int print_arr(char *parr);

int main(){
    int i;
    char arr1[40] = "plz copy me!";
    char arr2[40] = "hello";

    printf(" ---------- 복사 전 ---------- \n");
    print_arr(arr2);

    copy_arr(arr1, arr2);

    printf(" ---------- 복사 후 ---------- \n");
    print_arr(arr2);


    return 0;
}

int copy_arr(char *parr1, char *parr2){
    int count = 0;

    while(parr1[count]){
        parr2[count] = parr1[count];
        count++;
    }
    /* 마지막에 Null 넣어주기! (detail) */
    parr2[count] = '\0';

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