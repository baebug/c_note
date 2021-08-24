/* fopen 의 "r+" 인자 이용해보기 */
#include <stdio.h>
int main(){
    FILE *fp = fopen("a.txt", "r+");
    /*
    r+ : 읽기 및 쓰기 형식으로 열겠다. 파일 없으면 안열고 기존 내용 지우지 않는다.
    w+ : 읽기 및 쓰기 형식으로 열겠다. 파일 없으면 만들고 기존 내용 지우겠다.
    a  : 덧붙이기(append) 형식으로 열겠다.
    */
    char data[100];

    fgets(data, 100, fp);
    printf("현재 파일에 있는 내용 : %s \n", data);

    fseek(fp, 5, SEEK_SET);
    /*
    쓰기 - 읽기 모드 전환을 위해서는 무조건
    fseek 함수와 같은 '파일 위치 지정자 설정 함수'들을 호출해야 한다.
    fseek(fp, 0, SEEK_CUR) or fflush(fp)
    */
    fputs("is nothing on this file", fp);

    fclose(fp);

    return 0;
}