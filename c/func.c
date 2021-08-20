#include <stdio.h>

int plus_array(int* parr);
int max_number(int* parr);
int sort_array(int* parr);

int main(){
    int i;
    int arr[5];

    printf("원소를 차례대로 입력해주세요. (5개) \n");
    for(i = 0; i < 5; i++){
        printf("%d번째 원소 : ", i+1);
        scanf("%d", &arr[i]);
    }

    /* &arr[0] == arr */
    max_number(arr);
    plus_array(arr);

    printf("숫자 1씩 더하는중 ... \n");

    for(i = 0; i < 5; i++){
        printf("%d번째 원소 : %d \n", i+1, arr[i]);
    }

    sort_array(arr);

    printf("크기순으로 정리하는 중 ... \n");

    for(i = 0; i < 5; i++){
        printf("%d번째 원소 : %d \n", i+1, arr[i]);
    }

    return 0;
}

int plus_array(int* parr){
    int i;
    for(i = 0; i < 5; i++){
        /* *(parr + i) == parr[i] */
        *(parr+i) += 1;
    }
    return 0;
}

int max_number(int* parr){
    int i, max = 0;
    for(i = 0; i < 5; i++){
        if(*(parr+i) > max){
            max = *(parr+i);
        }
    }
    printf("배열의 최대 수는 %d입니다. \n", max);
    return 0;
}

int sort_array(int* parr){
    int i, j, temp;
    for(i = 0; i < 5; i ++){
        /* j는 i부터 array의 끝까지 */
        for(j = i; j < 5; j++){
            if(parr[j] > parr[i]) {
                /*
                parr[j] 가 위치상 parr[i] 보다 뒤에 있는 원소인데
                parr[j]의 값이 더 큰 경우 swich 해준다.
                parr[j] = *(parr+j)
                */
                temp = parr[j];
                parr[j] = parr[i];
                parr[i] = temp;
            }
        }
    }

    return 0;
}