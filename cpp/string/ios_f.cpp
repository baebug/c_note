#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 쓰기 준비
    /* test.txt 가 존재하지 않을 경우, test.txt 를 생성한 뒤 출력한다.
    이미 존재한다면, 해당 파일의 내용이 전부 지워지고 새로운 내용으로 덮어 씌어지게 된다.
    두 번째 인자로 std::ios::app 옵션을 주면 기존 내용을 지우지 않고 뒤에 쓴다. */
    std::ofstream out("test.txt", std::ios::app);

    std::string s;
    if (!out.is_open()) {
        /* 없으면 만들기 때문에 굳이 이 부분이 필요없다. */
        std::cout << "파일을 찾을 수 없습니다! " << std::endl;
    } else {
        out << "이것도 쓰자~~";
    }

    return 0;
}

/*
ios::binary : 
ios::app    : 
ios::ate    : 자동으로 파일 끝에서부터 읽기와 쓰기를 실시한다. (파일을 열 때 위치 지정자가 파일 끝을 가리킨다.)
ios::trunc  : 파일 스트림을 열면 기존의 내용이 모두 지워진다. (ofstream 의 default)
ios::in     : 파일에 입력을 할 지 지정한다. (ifstream 의 default)
ios::out    : 파일에 출력을 할 지 지정한다. (ofstream 의 default)

app 과 ate 는 비슷해 보이지만 다르다.
app 은 원본 파일의 내용을 보장하지만, ate 는 위치 지정자를 그 이전으로 옮길 수 있다. (사실 ate 쓸 일 거의 없음)
*/