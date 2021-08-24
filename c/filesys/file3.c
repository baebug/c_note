/* 한 글자씩 입력받기 */
#include <stdio.h>

int main(){
    FILE *fp = fopen("a.txt", "r");
    char c;

    /*
    fgetc = fp에서 문자 하나를 얻어 옴
    EOF = End of File = SEEK_END
    fseek(fp, 0, SEEK_SET), SEEK_SET = 파일의 맨 처음 (현재: CUR, 끝: END)
    > position indicator를 세번째 인자로부터 두번째 인자만큼 떨어진 곳으로 이동
    */
    while((c = fgetc(fp)) != EOF){
        printf("%c, ", c);
    }

    fclose(fp);

    return 0;
}