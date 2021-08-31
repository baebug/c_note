#include <string>
#include <iostream>

class Employee {
    /* Manager 클래스의 멤버 함수가 사용하므로 protected */
    protected:
    std::string name;
    int age;

    std::string role;   // 직책
    int rank;

    public:
    Employee(std::string name, int age, std::string role, int rank)
    : name(name), age(age), role(role), rank(rank) {}

    Employee(const Employee& e) {   // 복사 생성자
        name = e.name;
        age = e.age;
        role = e.role;
        rank = e.rank;
    }

    Employee() {}                   // 디폴트 생성자

    std::string print_name() {
        return name;
    }

    virtual int calculate_pay() {
        return 200 + rank * 50;
    }

    virtual void print_info() {
        std::cout << name << "(" << role << ", " << age << ") ==> " << calculate_pay() << " 만원" << std::endl;
    }
};

class Manager : public Employee {
    int year_of_service;

    public:
    Manager(std::string name, int age, std::string role, int rank, int year_of_service)
    :   year_of_service(year_of_service),
        Employee(name, age, role, rank) {}

    Manager(const Manager& m)
    :   Employee(m.name, m.age, m.role, m.rank) {
        year_of_service = m.year_of_service;
    }

    Manager() : Employee() {}

    int calculate_pay() {
        return 200 + 50 * rank + 5 * year_of_service;
    }

    void print_info() {
        std::cout << name << "(" << role << ", " << age << ", " << year_of_service << "년 차) ==> " << calculate_pay() << " 만원" << std::endl;
    }
};

/* 각 클래스 별 데이터를 따로 보관하고 있는게 문제, 더 늘어나면 힘들다.
업 캐스팅을 통해 Employee* 가 Manager도 가리킨다면 어떨까?
하지만 그렇게 하면 Manager 의 멤버 함수를 사용할 때 Employee 의 멤버 함수가 사용된다. (오버라이딩 무시) */
class EmployeeList {
    int alloc_employee;         // 할당한 총 직원 수 (memory_capacity)
    int current_employee;       // 현재 직원 수     (string_length)
    Employee **employee_list;   // 직원 데이터, Employee* 객체를 담는 배열로 사용할 것이기 때문에 Employee** 타입이다.

    public:
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
        current_employee = 0;

        employee_list = new Employee*[alloc_employee];
    }
    ~EmployeeList() {
        for(int i = 0; i < current_employee; i++){
            delete employee_list[i];
        }

        delete[] employee_list;
    }

    void add_employee(Employee* employee);

    int current_employee_num() { return current_employee; }

    void print_employee_info();
};

void EmployeeList::add_employee(Employee* employee) {
    /* 꽉 찼으면 정원 5명 늘리기 */
    if (current_employee == alloc_employee) {
        std::cout << " --- 직원의 정원이 가득 찼습니다. --- " << std::endl;
        Employee **prev_employee_list = employee_list;

        alloc_employee += 5;
        employee_list = new Employee*[alloc_employee];

        for(int i = 0; i < current_employee; i++){
            employee_list[i] = prev_employee_list[i];
        }
        std::cout << " --- 정원을 5 만큼 늘렸습니다. --- " << std::endl;
        delete[] prev_employee_list;
    }

    employee_list[current_employee] = employee;
    std::cout << employee->print_name() << " 입사 " << std::endl;
    current_employee++;
}

void EmployeeList::print_employee_info() {
    int total_pay = 0;
    for(int i = 0; i < current_employee; i++){
        employee_list[i]->print_info();
        total_pay += employee_list[i]->calculate_pay();
    }

    std::cout << "총 비용 : " << total_pay << " 만원 " << std::endl;
}


int main(){
    EmployeeList emp_list(3);
    emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
    emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

    emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
    emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
    emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
    emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
    emp_list.add_employee(new Employee("길", 36, "인턴", -2));
    
    emp_list.print_employee_info();

    return 0;
}