#include <stdio.h>
#include <string.h>

int count_digit(int num);
int change_int(char *str);

int main(int argc, char **argv){
    // printf("받은 인자의 개수 : %d \n", argc);
    int int1, int2;

    // int var1 = (int)*argv[1];
    // int var2 = (int)*argv[3];
    // printf("var1 : %c \n", var1);
    // printf("var2 : %c \n", var2);
    int1 = change_int(argv[1]);
    int2 = change_int(argv[3]);

    switch(*argv[2])
    {
    case '+':
        printf("계산 결과: %d \n", int1 + int2);
        break;

    case '-':
        printf("계산 결과: %d \n", int1 - int2);
        break;

    case '*':
        printf("계산 결과: %d \n", int1 * int2);
        break;

    case '/':
        printf("계산 결과: %f \n", (double)int1 / int2);
        break;
    
    default:
        break;
    }

    return 0;
}

int count_digit(int num){
    /* 4 들어오면 1000이 나간다. */
    int i;
    int d = 1;
    for(i = num-1; i > 0; i--){
        d *= 10;
    }

    return d;
}

int change_int(char *str){
    int i, j;
    int len = strlen(str);
    int nums = 0;
    while(len > 0){
        nums += (*str-48) * count_digit(len);
        str++;
        len--;
    }

    return nums;
}