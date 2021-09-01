/* ios 클래스에서 관리하는 스트림의 상태를 나타내는 4가지 flag 
goodbit : 스트림에 입출력 작업이 가능하다.
badbit  : 스트림에 복구 불가능한 오류가 발생했다.
failbit : 스트림에 복구 가능한 오류가 발생했다.
eofbit  : 입력 작업시 EOF (end of file) 에 도달했다.

std::cin.fail()             : failbit 혹은 badbit 가 true 면 ture 값이 리턴된다.
std::cin.clear()            : (인자 없는 기준) 플래그를 goodbit 으로 초기화 시킨다.
std::cin.ignore(100, '\n')  : 두 번째 인자가 나올 때까지 버퍼에서 무시 (최대 첫 번째 인자)
*/

#include <iostream>
#include <string>

int main(){
    int t;
    while(1) {
        /* 1번 방법 : 입력 형식 변경 set format
        몇 진법으로 처리할 지 보관하는 basefield 의 값을 초기화 하고 hex 를 적용 
        형식 플래그 hex 는 ios_base 에 선언되어 있는 단순한 상수'값' 이다.
        std::cin.setf(std::ios_base::hex, std::ios_base::basefield);    */

        /* 2번 방법 : 조작자 (ios 에 정의되어 있는 함수) */
        std::cin >> std::hex >> t;
        std::cout << "입력 :: " << t << std::endl;
        if(std::cin.fail()) {
            std::cout << "마. 장난치지 마라" << std::endl;
            std::cin.clear();
        }
        if (t == 0) break;
    }

    return 0;
}