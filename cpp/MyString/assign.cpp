#include <iostream>
#include <string.h>

/* assign 함수는 '지정하다' 라는 뜻을 가진 함수로, 
우리가 흔히 생각하는 '=' 과 동일한 역할을 한다.
아~ 그런 역할을 하는 assign 함수를 만들자고? */

class MyString {
    char *string_content;
    int string_length;
    int memory_capacity;

    public:
    int length() const;
    int capacity() const;
    void reserve(int size);
    char at(int i) const;

    void print() const;
    void println() const;

    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

    MyString& erase(int loc, int num);

    int find(int find_from, MyString& str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;

    int compare(const MyString& str) const;

    MyString(char c);                   /* 문자 하나로 생성 */
    MyString(const char* str);          /* 문자열(const char*)로부터 생성 */
    MyString(const MyString& str);      /* 복사 생성자 T (const T& sth) */
    ~MyString();
};

/* 어차피 문자열은 변수에 들어가 있으므로 개행문자의 공간을 마련할 필요가 없다. */
MyString::MyString(char c){
    string_length = 1;
    memory_capacity = string_length;
    string_content = new char[string_length];
    string_content[0] = c;
}

MyString::MyString(const char* str){
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    
    for(int i = 0; i < string_length; i++){
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString& str){
    string_length = str.string_length;
    memory_capacity = string_length;
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
int MyString::capacity() const { return memory_capacity; }

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

/* 잘 이해가 안되네? 복사 느낌인가? ㅇㅇ 맞음
짱 긴 string 에서 짧은 string 으로 가면 재할당이 이루어지지 않음 (정상)
짧은 string 에서 긴 string 으로 가면 재할당이 이루어짐 (비정상) -> 공간이 충분한 지 모른다.
따라서 얼마나 많은 공간이 할당되어 있는지도 표기해주는 방식이 좋아보임. (memory_capacity 라는 멤버 변수 추가)
*/
MyString& MyString::assign(const MyString& str){
    if (str.string_length > memory_capacity) {
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for(int i = 0; i != str.string_length; i++){
        string_content[i] = str.string_content[i];
    }

    string_length = str.string_length;

    return *this;
}

MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for(int i = 0; i != str_length; i++){
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}

/* 이전 string_content (char*) 를 다른 이름으로 바꾸고 새로 할당받는다.
기존의 string을 새로 할당받은 string에 넣는다.
기존의 string을 free(delete) 해준다. */
void MyString::reserve(int size){
    if (size > memory_capacity){
        char* prev_string_contest = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for(int i = 0; i != string_length; i++){
            string_content[i] = prev_string_contest[i];
        }

        delete[] prev_string_contest;
    }
}

char MyString::at(int i) const {
  if (i >= string_length || i < 0)
    return '\0';
  else
    return string_content[i];
} 

MyString& MyString::insert(int loc, const MyString& str){
    if(loc < 0 || loc > string_length) return *this;

    if(string_length + str.string_length > memory_capacity){

        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        int i;
        for(i = 0; i != loc; i++){
            string_content[i] = prev_string_content[i];
        }
        for(int j = 0; j != str.string_length; j++){
            string_content[i + j] = str.string_content[j];
        }
        /* ; mean i = loc */
        for(; i != string_length; i++ ) {
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;

        return *this;
    }
    /* 초과하지 않는 경우 굳이 동적할당 할 필요가 없다. 
    효율적인 insert를 위해, 밀리는 부분을 먼저 뒤로 밀어버린다. */
    for(int i = string_length - 1; i >= loc; i--) {
        /* 앞에서부터 밀면 데이터 날라감 */
        string_content[i + str.string_length] = string_content[i];
    }
    for(int i = 0; i != str.string_length; i++){
        string_content[i + loc] = str.string_content[i];
    }

    string_length = string_length + str.string_length;

    return *this;
}

MyString& MyString::insert(int loc, const char* str){
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c){
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num){
    if(loc < 0 || loc > string_length || num < 0 || num > string_length){
        return *this;
    }

    for(int i = loc + num; i != string_length; i++){
        string_content[i - num] = string_content[i];
    }

    string_length -= num;
    return *this;
}

int MyString::find(int find_from, MyString& str) const {
    int i, j;
    if(str.string_length == 0) return -1;
    for(i = find_from; i <= string_length - str.string_length; i++){
        for(j = 0; j < str.string_length; j++){
            if (string_content[i + j] != str.string_content[j]) break;
        }

        if (j == str.string_length) return i;
    }

    return -1;  // 못 찾았다.
}

int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
    for (int i = 0; i < std::min(string_length, str.string_length); i++){
        if (string_content[i] > str.string_content[i]){
            return 1;
        }
        else if (string_content[i] < str.string_content[i]){
            return -1;
        }
    }

    if (string_length == str.string_length) return 0;
    else if (string_length > str.string_length)
        return 1;

    return -1;

}

int main(){
    MyString *bong = new MyString('b');
    MyString hong("mojjang");

    std::cout << bong->length() << std::endl;
    std::cout << hong.length() << std::endl;

    bong->print();
    bong->println();
    hong.println();

    MyString str1("very long string");
    MyString str2("<some string inserted between>");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();

    str1.insert(5, str2);
    str1.println();

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();

    MyString str3("this is a very very long string");
    std::cout << "Location of first <very> in the string : " << str3.find(0, "very")
        << std::endl;
    std::cout << "Location of second <very> in the string : "
        << str3.find(str3.find(0, "very") + 1, "very") << std::endl;

    MyString str4("abcdef");
    MyString str5("abcde");

    std::cout << "str4 and str5 compare : " << str4.compare(str5) << std::endl;

    return 0;
}

