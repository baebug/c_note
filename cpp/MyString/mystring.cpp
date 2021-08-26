/* 기존 C 언어에서는 문자열을 나타내기 위해
널 종료 문자열 (Null-terstd::minating string) 이라는 개념을 도입하고,
문자열 끝에 NULL 문자를 붙여줌으로써 문자열을 나타내었다. */
#include <iostream>
#include <string.h>

/* 왜 객체에 문자열 데이터를 직접 보관하지않고 저장공간을 가리키는 포인터를 보관하느냐?
= 문자열 데이터의 크기가 바뀔 때 대응하기 위해서 */
class MyString {
    char *string_content;
    int string_length;

    public:
    int length() const;
    void print() const;
    void println() const;

    MyString(char c);                   /* 문자 하나로 생성 */
    MyString(const char* str);          /* 문자열(const char*)로부터 생성 */
    MyString(const MyString& str);      /* 복사 생성자 T (const T& sth) */
    ~MyString();
};

/* 어차피 문자열은 변수에 들어가 있으므로 개행문자의 공간을 마련할 필요가 없다. */
MyString::MyString(char c){
    string_length = 1;
    string_content = new char[string_length];
    string_content[0] = c;
}

MyString::MyString(const char* str){
    string_length = strlen(str);
    string_content = new char[string_length];
    
    for(int i = 0; i < string_length; i++){
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString& str){
    string_length = str.string_length;
    /* 깊 은 복 사*/
    string_content = new char[string_length];

    for(int i = 0; i < string_length; i++){
        string_content[i] = str.string_content[i];
    }
}

/* marine 이 죽을 때 이름 없앤 것처럼 생각하자.
string_content 를 동적 할당으로 처리했기 때문에 반드시 해주어야 한다. */
MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }

void MyString::print() const {
    for(int i = 0; i != string_length; i++){
        std::cout << string_content[i];
    }
}

void MyString::println() const {
    for(int i = 0; i != string_length; i++){
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}

int main(){
    MyString *bong = new MyString('b');
    MyString hong("mojjang");

    std::cout << bong->length() << std::endl;
    std::cout << hong.length() << std::endl;

    bong->print();
    bong->println();
    hong.println();

    return 0;
}

