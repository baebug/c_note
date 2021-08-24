/* a.txt 에 내용을 기록한다. */
#include <stdio.h>

int main(){
    /* 스트림을 만들고 만든 포인터를 fp로 리턴한다. */
    FILE *fp;
    fp = fopen("a.txt", "w");

    /* 가끔 fopen 함수는 NULL을 리턴함. (문제가 발생해서 파일을 열지 못 한 경우) */
    if (fp == NULL){
        printf("Write Error!! \n");
        return 0;
    }

    fputs("Hello World!!! \n", fp);

    /* 항상 다 쓴 다음에는 닫아줘야 함 */
    fclose(fp);

    return 0;
}