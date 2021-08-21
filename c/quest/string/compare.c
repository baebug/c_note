#include <stdio.h>

int compare_arr(char *parr1, char *parr2);
int compare_arr2(char *parr1, char *parr2);

int main(){
    char arr1[] = "abcd";
    char arr2[] = "abcde";

    compare_arr(arr1, arr2);
    if(compare_arr2(arr1, arr2)){
        printf("(2): 일치합니다. \n");
    } else {
        printf("(2): 다릅니다. \n");
    }

    return 0;
}

int compare_arr2(char *parr1, char *parr2){
    while(*parr1){
        if(*parr1 != *parr2){
            return 0;
        }

        parr1++;
        parr2++;
    }
    /* 덕분에 arr2의 길이를 측정안해도 된다. */
    if(*parr2 == '\0') return 1;

    return 0;
}

int compare_arr(char *parr1, char *parr2){
    int i = 0;
    int j = 0;
    int k = 0;
    
    /* i = arr1의 length */
    while(parr1[i]){
        i++;
    }

    /* j = arr2의 length */
    while(parr2[j]){
        j++;
    }

    /* k = arr1과 arr2 사이에 일치하는 원소의 개수 */
    while(parr1[k] && parr2[k]){
        if(parr1[k] == parr2[k]){
            k++;
        } else break;
    }

    if(i == j && i == k) {
        /* i = j = k 일 때, */
        printf("(1): 두 문장은 일치합니다. \n");
    } else printf("(1): 달라요 \n");
    
    return 0;
}
