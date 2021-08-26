#include <iostream>
#include <string.h>

class String {
    char *context;

    public:
    void print_context(){
        std::cout << context << std::endl;
    }
    void print_str_len(){
        std::cout << strlen(context) << std::endl;
    }


    String(char input);
    String(const char *input);
};

/* char 원소 2개 배열만큼의 공간을 할당받고 0번 인자로 입력받은 char을 넣는다. */
String::String(char input) {
    context = new char[2];  
    context[0] = input;
}

/* const char * 입력받는 거 항상 생각하기 */
String::String(const char *input) {
    std::cout << "문자열 생성. size : " << strlen(input) << std::endl;
    context = new char[strlen(input) + 1];
    strcpy(context, input);
}

int main(){
    
    String *str1 = new String('a');
    String *str2 = new String("abcd");

    str1->print_context();
    str1->print_str_len();
    str2->print_context();
    str2->print_str_len();

    delete str1;
    delete str2;

    return 0;
}