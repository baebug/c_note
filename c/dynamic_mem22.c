#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int i;
    int x, y;
    int **arr;  // 우리는 arr[x][y]를 만들 것이다.

    printf("arr[x][y]를 만들 것입니다. x, y를 차례로 입력해주세요. : \n");
    scanf("%d %d", &x, &y);

    /* int* 형의 원소를 x개 가지는 1차원 배열 생성 */
    arr = (int **)malloc(sizeof(int *) * x);
    
    for(i = 0; i < x; i++){
        /* int 형의 원소를 y개 가지는 2차원 배열 생성 */
        arr[i] = (int *)malloc(sizeof(int) * y);
    }

    printf("생성 완료! \n");

    for(i = 0; i < x; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}