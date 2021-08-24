/* fscanf 이용하기 */
#include <stdio.h>

int main(){
    FILE *fp = fopen("a.txt", "r");
    char data[100];

    if (fp == NULL){
        printf("파일 열기 오류 \n");
        return 0;
    }

    printf(" ----- 입력 받은 단어들 ----- \n");
    
    /*
    scanf는 stdin 에서만 입력을 받지만
    fscanf는 임의의 스트림에서도 입력을 받을 수 있는 좀 더 일반화 된 함수

    fscanf(stdin, "%s", data);
    == scanf("%s", data);

    fprintf(stdout, "Hello, World! \n");
    == printf("Hello, World! \n");
    */
    while(fscanf(fp, "%s", data) != EOF){
        printf("%s \n", data);
    }

    fclose(fp);

    return 0;
}