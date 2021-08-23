#include <stdio.h>
enum { 강병민 = 10, 강봉권, 김태홍, 배충현 };

int main(){
    int palette = 강봉권;
    switch (palette) {
        case 강병민:
            printf("palette : 강병민 \n");
            break;
        case 강봉권:
            printf("palette : %d \n", 강봉권);
            break;
        case 김태홍:
            printf("palette : 김태홍 \n");
            break;
        case 배충현:
            printf("palette : 배충현 \n");
            break;

    }

    return 0;
}