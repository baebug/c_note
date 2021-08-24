/* fgets 로 a.txt 에서 내용을 입력받는다. */

#include <stdio.h>
int main(){
    FILE *fp = fopen("a.txt", "r"); // write, read ...
    char buf[20];   // 내용을 입력받을 곳
    if (fp == NULL){
        printf("read error! \n");
        return 0;
    }
    /* 어디에 얼마나 어떻게 */
    fgets(buf, 20, fp);
    printf("입력받는 내용 : %s \n", buf);
    fclose(fp);

    return 0;
}