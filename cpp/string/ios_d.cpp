/* 파일 전체 읽기 */

#include <fstream>
#include <iostream>
#include <string>

int main(){
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        /* 위치 지정자를 파일 끝으로 옮긴다. get area 라서 seekg 인가? (반대는 put area) */
        in.seekg(0, std::ios::end); // seekg(얼마나 떨어져 있는지, 파일 내 위치 지정자의 위치)

        /* 그 위치를 읽는다. (파일 사이즈) */
        int size = in.tellg();      // 시작 지점으로부터의 위치 지정자 위치를 리턴한다. (파일의 크기 = 바이트 단위)

        /* 사이즈 만큼의 문자열을 할당한다. */
        s.resize(size);

        /* 위치 지정자를 다시 맨 앞으로 옮긴다. */
        in.seekg(0, std::ios::beg);

        /* 파일 전체를 읽어서 문자열에 저장한다.
        read(첫 원소의 주소값, 얼마나 넣을지) */
        in.read(&s[0], size);   // &s[0] 이랑 s 랑 같은거 아니었나?
        std::cout << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }

    return 0;
}