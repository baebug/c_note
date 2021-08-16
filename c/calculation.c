#include <stdio.h>

int main()
{
    /* 일반 연산 */
    int a, b;
    a = 10;
    b = 3;

    printf("a + b 는 %d 입니다. \n", a + b);
    printf("a - b 는 %d 입니다. \n", a - b);
    printf("a * b 는 %d 입니다. \n", a * b);
    printf("a / b 는 %d 입니다. \n", a / b);
    // 3, int인 두 수 사이의 연산이라 결과값도 int로 나왔다.
    printf("a를 b로 나눈 나머지(%%)는 %d 입니다. \n", a % b);
    // %를 print하려면 %%를 써야한다. (%d, %s 등이랑 헷갈려서)

    /* 비트 연산 */
    int c = 0xAF;   // 10101111
    int d = 0xB5;   // 10110101

    printf("%x \n", c & d);     // 10100101
    printf("%x \n", c | d);     // 10111111
    printf("%x \n", c ^ d);     // 00011010
    printf("%x \n", ~c);        // 01010000, 왜 ffffff50이 나오는가? int형 = 4byte = 32bit
    printf("%x \n", c << 2);    // 1010111100
    printf("%x \n", d >> 3);    // 00010110
    return 0;

    // 2의 보수법으로 음수를 표현한다. (2진법 기준. 반전시킨 뒤 +1)
    // overflow를 조심하자
}