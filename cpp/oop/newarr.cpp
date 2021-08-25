#include <iostream>

int main(){
    int arr_size;
    std::cout << "배열 사이즈 얼마? : " << std::endl;
    std::cin >> arr_size;
    /* type *(ptr_name) = new type[size] */
    int *parr = new int[arr_size];
    for(int i = 0; i < arr_size; i++){
        std::cout << "배열의 " << i + 1 << " 번 째 원소를 입력해주세요." << std::endl;
        std::cin >> parr[i];
    }
    for(int i = 0; i < arr_size; i++){
        std::cout << parr[i] << std::endl;
    }

    delete[] parr;

    return 0;
}