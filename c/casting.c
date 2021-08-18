#include <stdio.h>
#include <stdlib.h> // abs
#include <math.h>   //fabsf

int main()
{
    float f;
    
    printf("실수를 입력하시오 : ");
    scanf("%f", &f);
    /*
    int a = (int)100 * f;
    int b = 100 * (int)f;
    int i = abs(a - b);
    */
    int i = fabsf((int)100*f - 100*(int)f);
    if (i >= 0 && i < 10) {
        printf("i=0%d \n", i);
    } else {
        printf("i=%d \n", i);
    }
    return 0;
}