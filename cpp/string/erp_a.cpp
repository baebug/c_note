#include <string>
#include <iostream>

class Employee {
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

    void print_info() {
        std::cout << name << "(" << role << ", " << age << ") ==> " << calculate_pay() << " 만원" << std::endl;
    }

    int calculate_pay() {
        return 200 + rank * 50;
    }
};

/* 갑자기 차장 이상 급들은 관리데이터에 근속 년수를 포함시켜 월급 추가해달라는 요청이 들어옴.
이거 왠지 동물키우기 확장판 (새, 물고기)의 상황..? */
class Manager {
    std::string name;
    int age;

    std::string role;
    int rank;
    int year_of_service;    // 추가된 근속 년수

    public:
    Manager(std::string name, int age, std::string role, int rank, int year_of_service)
    :   name(name),
        age(age),
        role(role),
        rank(rank),
        year_of_service(year_of_service) {}

    Manager(const Manager& m) {     // 복사 생성자
        name = m.name;
        age = m.age;
        role = m.role;
        rank = m.rank;
        year_of_service = m.year_of_service;
    }

    Manager() {}

    std::string print_name() {
        return name;
    }

    int calculate_pay() {
        return 200 + rank * 50 + 5 * year_of_service;
    }

    void print_info() {
        std::cout << name << " (" << role << ", " << age << ") ==> " << calculate_pay() << " 만원" << std::endl;
    }
};

/* 매니저라는 새로운 관리 대상이 생기면서 Manager 배열도 추가해주어야 한다. 지옥인가? */
class EmployeeList {
    int alloc_employee;         // 할당한 총 직원 수 (memory_capacity)

    int current_employee;       // 현재 직원 수     (string_length)
    int current_manager;        // 현재 매니저 수

    Employee **employee_list;   // 직원 데이터, Employee* 객체를 담는 배열로 사용할 것이기 때문에 Employee** 타입이다.
    Manager **manager_list;     // Manager* 객체를 담는 배열

    public:
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
        current_employee = 0;
        current_manager = 0;

        employee_list = new Employee*[alloc_employee];
        manager_list = new Manager*[alloc_employee];
    }
    ~EmployeeList() {
        for(int i = 0; i < current_employee; i++){
            delete employee_list[i];
        }
        for(int i = 0; i < current_manager; i++){
            delete manager_list[i];
        }
        delete[] employee_list;
        delete[] manager_list;
    }

    void add_employee(Employee* employee);
    void add_manager(Manager* manager);

    int current_employee_num() { return current_employee + current_manager; }

    void print_employee_info();
};

void EmployeeList::add_employee(Employee* employee) {
    /* 꽉 찼으면 정원 5명 늘리기 */
    if (current_employee == alloc_employee) {
        std::cout << " --- Employee 의 정원이 가득 찼습니다. --- " << std::endl;
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
    std::cout << "직원 " << employee->print_name() << " 입사 " << std::endl;
    current_employee++;
}

void EmployeeList::add_manager(Manager* manager) {
    if (current_manager == alloc_employee) {
        std::cout << " --- Manager 의 정원이 가득 찼습니다. --- " << std::endl;
        Manager **prev_manager_list = manager_list;

        alloc_employee += 5;
        manager_list = new Manager*[alloc_employee];

        for(int i = 0; i < current_manager; i++){
            manager_list[i] = prev_manager_list[i];
        }
        std::cout << " --- 정원을 5 만큼 늘렸습니다. --- " << std::endl;
        delete[] prev_manager_list;
    }

    manager_list[current_manager] = manager;
    std::cout << "매니저 " << manager->print_name() << " 입사 " << std::endl;
    current_manager++;
}

void EmployeeList::print_employee_info() {
    int total_pay = 0;
    for(int i = 0; i < current_employee; i++){
        employee_list[i]->print_info();
        total_pay += employee_list[i]->calculate_pay();
    }
    for(int i = 0; i < current_manager; i++){
        manager_list[i]->print_info();
        total_pay += manager_list[i]->calculate_pay();
    }

    std::cout << "총 비용 : " << total_pay << " 만원 " << std::endl;
}

int main(){
    EmployeeList emp_list(3);
    emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
    emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

    emp_list.add_manager(new Manager("유재석", 41, "부장", 7, 12));
    emp_list.add_manager(new Manager("정준하", 43, "과장", 4, 15));
    emp_list.add_manager(new Manager("박명수", 43, "차장", 5, 13));
    emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
    emp_list.add_employee(new Employee("길", 36, "인턴", -2));
    
    emp_list.print_employee_info();

    return 0;
}