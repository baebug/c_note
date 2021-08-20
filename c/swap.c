#include <stdio.h>

int swap();

int main() {
    int a = 5;
    int b = 10;

    printf("a: %d\nb: %d\n\n", a, b);
    /* a와 b의 주소를 넣어준다. */
    swap(&a, &b);

    printf("a: %d\nb: %d\n\n", a, b);

    return 0;
}

int swap(int* num1, int* num2) {
    /*
    들어온 두개의 인자는 주소를 나타냄.(누가 사는지는 관심 없는게 포인트) 105호, 208호
    임시 거주지 만들고
    105호에 사는 사람을 임시 거주지로
    208호에 사는 사람을 105호로
    임시 거주지에 있는 사람을 208호로
    */
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;

    return 0;
}