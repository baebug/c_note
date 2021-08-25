#include <iostream>

class Misae {
    private:
    int age;
    int iq;

    public:
    void view_stat(){
        std::cout << "나이   : " << age << std::endl;
        std::cout << "아이큐 : " << iq << std::endl;
    }
    void set_age(int _age){
        age = _age;
    }
    void increase_iq(int inc);

    /* default constructor (= default) */
    Misae() {
        age = 28;
        iq = 110;
    }

    /* constructor with arguments */
    Misae(int _age, int _iq){
        age = _age;
        iq = _iq;
    }
};

void Misae::increase_iq(int inc){
        iq += inc;
}

int main() {
    Misae bong = Misae(10, 80);     // 명시적 방법
    Misae yoon(27, 100);            // 암시적 방법
    Misae hong;                     // default
    bong.set_age(30);
    bong.view_stat();
    yoon.view_stat();
    hong.view_stat();
    
    bong.increase_iq(10);
    bong.view_stat();

    return 0;
}
