/* 파일 전체를 한 줄씩 읽기 (마지막에 빈 줄 하나 출력 됨) */

#include <fstream>
#include <iostream>
#include <string>

int main(){
    /* 파일 읽기 준비 */
    std::ifstream in("test.txt");
    char buf[100];

    if (!in.is_open()) {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
        return 0;
    }

    std::string s;
    while (in) {
        /* 파일에서 '\n' 가 나올 때 까지 최대 지정한 크기 -1 (100 - 1) 만큼 읽는다.
        in.getline(buf, 100, '-'); 세 번째 인자를 통해 원하는 문자를 찾을 수 있다.
        지정한 문자가 나오기 전에 버퍼가 다 차게 된다면 failbit 가 켜지므로 주의 */
        // in.getline(buf, 100);

        /* 이 getline 함수는 ifstream 이 아니라 std::string 에 정의되어 있는 함수
        첫 번째 인자로 ifstream 객체, 두 번째 인자로 입력 받은 문자열을 저장할 string 객체를 받는다. 
        굳이 버퍼의 크기를 지정하지 않아도 알아서 개행문자 혹은 파일의 끝이 나올 때 까지 입력받는다.
        원하는 문자 찾기는 안 되는듯, 마지막 줄은 왜 두 번 반복되는가? */
        getline(in, s);
        std::cout << s << std::endl;    // buf -> s
    }

    return 0;
}