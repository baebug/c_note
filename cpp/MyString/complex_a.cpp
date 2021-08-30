#include <iostream>
#include <cstring>

/* operator 연산자 앞 을 기준으로 뒤 를 수행한다.
a + b; = a.operator+(b); */

/* 자기 자신을 리턴하는 이항 연산자는 멤버 함수로, 아닌 애들은 외부 함수로 정의합시다! */

class Complex {
    private:
    double real, img;   // 실수와 허수

    double get_number(const char *str, int from, int to);

    public:
    /* 연산자 오버로딩 없이 구현하면
    Complex plus(const Complex& c);     // Complex 타입을 반환하는 함수
    Complex minus(const Complex& c);    // Complex 타입을 인자로 받아 c 라는 별명을 붙이고 함수 내용을 수행
    Complex times(const Complex& c);
    Complex divide(const Complex& c);

    a + b / c + d = a.plus(b.divide(c)).plus(d)         */

    Complex(double real, double img) : real(real), img(img) {}  // initializer list
    Complex(const char *str);
    Complex(const Complex& c) { real = c.real, img = c.img; }    // 복사 생성자

    /* a = b = c 에서 b = c 가 b 를 리턴해야 a = b 가 제대로 수행된다.
    이때 Complex 타입이 아니라 굳이 Complex&을 리턴하는 이유는 대입 연산 이후에 불필요한 복사를 방지하기 위해서 */
    Complex& operator=(const Complex& c);
    /* 굳이 operator= 를 안만들어도 기능이 작동한다.
    왜 Why? 컴파일러가 디폴드 대입 연산자를 지원하기때문
    그 말은? 깊은 복사일 경우에는 직접 만들어주고, 이 외에는 있는거 쓰자.
    깊복: 클래스 내부적으로 동적으로 할당되는 메모리를 관리하는 포인터가 있는 등의 경우 (name) */

    Complex& operator+=(const Complex& c);  // 객체 내부의 상태를 변경하기 때문에 const 선언 x
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);

    void println() { std::cout << "(" << real << ", " << img << ")" << std::endl; }

    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend Complex operator/(const Complex& a, const Complex& b);

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "(" << c.real << ", " << c.img << ")";
    return os;
}

/* 연산자 오버로딩 이렇게 해놓고 const char* str 등 필요 인자별 생성자만 제대로 만들어두면 됨 */
Complex operator+(const Complex& a, const Complex& b) {
    Complex temp(a.real + b.real, a.img + b.img);
    return temp;
}

Complex operator-(const Complex& a, const Complex& b) {
    Complex temp(a.real - b.real, a.img - b.img);
    return temp;
}

Complex operator*(const Complex& a, const Complex& b) {
    Complex temp(a.real * b.real - a.img * b.img, a.real * b.img + a.img * b.real);
    return temp;
}

Complex operator/(const Complex& a, const Complex& b) {
    Complex temp(
        (a.real * b.real + a.img * b.img) / (b.real * b.real + b.img * b.img),
        (a.img * b.real - a.real * b.img) / (b.real * b.real + b.img * b.img));
    return temp;
}


Complex::Complex(const char *str) {
    int st = 0, end = strlen(str);
    real = 0.0;
    img = 0.0;

    int pos_i = -1;
    for(int i = 0; i != end; i++){
        if(str[i] == 'i'){
            pos_i = i;
            break;
        }
    }

    /* i 가 없는 경우 (str 이 그냥 실수) */
    if(pos_i == -1){
        real = get_number(str, st, end - 1);
        return;
    }

    /* i 가 있는 경우 (실수부 허수부 나눠서 생각) */
    real = get_number(str, st, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') {
        img *= -1.0;
    }
}

/* 생성자만 남기고 연산자 오버로딩 한 부분을 지워도 작동한다. 
우리가 a = a + "-1.1 + i3.923"; 이라는 문장을 사용하였을 때,
컴파일러는 a = a.operator+("-1.1 + i3.923"); 로 알아듣게 되는데
operator+(const Complex& c) 밖에 없기때문에 직접적으로 오버로딩 되지는 않지만 
다음 순위를 찾는 과정에서 Complex(const char *str) 생성자를 찾게 된다. 
즉, a = a.operator+(Complex("-1.1 + i3.923")); 가 수행된다. */

double Complex::get_number(const char *str, int from, int to) {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for(int i = from; i <= to; i++) {
        if(isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');  // 아스키 테이블에서 0 부터 9 까지 숫자들이 연속적으로 배열, '0' 빼면 실제 정수 값
        } else if (str[i] == '.') {
            integer_part = false;
        } else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else break;
    }

    if (minus) num *= -1.0;

    return num;
}

// Complex Complex::operator+(const char* str) {
//     int st = 0, end = strlen(str);
//     double str_real = 0.0, str_img = 0.0;

//     int pos_i = -1;
//     for(int i = 0; i != end; i++){
//         if(str[i] == 'i'){
//             pos_i = i;
//             break;
//         }
//     }

//     /* i 가 없는 경우 (str 이 그냥 실수) */
//     if(pos_i == -1){
//         str_real = get_number(str, st, end - 1);

//         Complex temp(str_real, str_img);
//         return (*this) + temp;
//     }

//     /* i 가 있는 경우 (실수부 허수부 나눠서 생각) */
//     str_real = get_number(str, st, pos_i - 1);
//     str_img = get_number(str, pos_i + 1, end - 1);

//     if (pos_i >= 1 && str[pos_i - 1] == '-') {
//         str_img *= -1.0;
//     }

//     Complex temp(str_real, str_img);
//     return (*this) + temp;
// }

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;

    return *this;
}

Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}

Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}

Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}

Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}

/* 자기 자신을 리턴하는 이항 연산자는 멤버 함수로, 아닌 애들은 외부 함수로 정의합시다! */

int main(){
    Complex a(0, 0);
    a = "-1.1 + i3.923" + a;
    a = a + a;

    a.println();

    a = a + "1.1 +i0.3";
    a.println();
    a = "1.1 +i0.3" + a;
    a.println();
    a += "1.1 +i0.3";
    std::cout << "a 의 값은 : " << a << " 이다." << std::endl;

    return 0;
}