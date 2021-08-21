#include <stdio.h>

struct Books
{
    /* 책 이름 */
    char name[30];
    /* 저자 이름 */
    char auth[30];
    /* 출판사 이름 */
    char publ[30];
    /* 대출 유무 */
    int borrowed;
};

int main(){
    /* struct Books 타입의 원소 3개를 가진 book_list라는 이름의 array */
    struct Books book_list[3];
    int i;

    for(i = 0; i < 3; i++){
        printf("%d번째 책 정보를 입력해주세요.", i+1);
        scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);
        book_list[i].borrowed = 0;
    }

    for(i = 0; i < 3; i++){
        printf(" ------------------------------- \n");
        printf("책 <%s>의 정보 \n", book_list[i].name);
        printf("저자     : %s \n", book_list[i].auth);
        printf("출판사   : %s \n", book_list[i].publ);

        if(book_list[i].borrowed == 0){
            printf("대출여부 : 안빌려감 \n");
        } else {
            printf("대출여부 : 빌려감 \n");
        }
    }

    return 0;
}