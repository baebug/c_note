/*
배열의 크기를 자유자재로 다룰 수 있으면 얼마나 좋을까? 에서 시작
현재는 '충분히 큰' 배열을 선언 >> 메모리 낭비로 이어진다.
'어떤 것'을 입력받고 그만큼 배열의 크기를 지정한다. 동적(가변) 메모리 할당.
*/

#include <stdio.h>
#include <stdlib.h> // malloc이 들어있는 곳

int main(int argc, char **argv){
    int SizeOfArray;
    int *arr;

    printf("만들고 싶은 배열의 원소 수 : ");
    scanf("%d", &SizeOfArray);

    /*
    malloc = memory allocation
    자신이 할당한 메모리의 시작 주소를 (void * 형으로) 리턴한다. 
    */
    arr = (int *)malloc(sizeof(int) * SizeOfArray);
    // int arr[SizeOfArray] 와 동일한 작업을 한 크기의 배열 생성

    /*
    할당받은 메모리를 다 사용하고 난 뒤 메모리 영역을 컴퓨터에게 돌려주는 역할
    free를 제대로 하지 않아 발생하는 문제를 메모리 누수(memory leak)라고 한다. 자리차지 ㄴ
    malloc은 Heap 영역에 위치한다.
    */
    free(arr);

    return 0;
}