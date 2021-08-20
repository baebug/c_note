#include <stdio.h>

int plus_arr2(int* parr2);

int main(){
    int i, j;
    int arr2[4][3];

    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){
            printf("%d번째 원소: ", 3*i + j + 1);
            scanf("%d", &arr2[i][j]);
        }
    }

    /* arr2 = &arr2[0] */
    plus_arr2(&arr2[0][0]);

    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){
            printf("%d번째 원소 : %d \n", 3*i + j + 1, arr2[i][j]);
        }
    }


    return 0;
}

int plus_arr2(int* parr2){
    int i, j;

    // for(i = 0; i < 4; i++){
    //     for(j = 0; j < 3; j++){
    //         *(parr2+3*i+j) += 1;
    //     }
    // }
    
    for(i = 0; i < 12; i++){
        parr2[i]++;
    }

    return 0;
}