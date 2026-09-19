#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int employeeId;
    string name;
public:
    Employee(int id, string n) {
        employeeId = id;
        name = n;
    }
    virtual double calculateSalary() = 0;
    void displayBasicDetails() {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
    }
};

class PermanentEmployee : public Employee {
public:
    double basicSalary, allowance;
    PermanentEmployee(int id, string n, double b, double a) : Employee(id, n) {
        basicSalary = b;
        allowance = a;
    }
    double calculateSalary() override {
        return basicSalary + allowance;
    }
};

class ContractEmployee : public Employee {
public:
    double hourlyRate;
    int hoursWorked;
    ContractEmployee(int id, string n, double rate, int hours) : Employee(id, n) {
        hourlyRate = rate;
        hoursWorked = hours;
    }
    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }
};

void displayPaySlip(Employee &e) {
    e.displayBasicDetails();
    cout << "Salary: " << e.calculateSalary() << endl;
}

int main() {
    PermanentEmployee p(101, "Steve", 45000.0, 7500.0);
    ContractEmployee c(102, "Tom", 600.0, 90);

    displayPaySlip(p);
    displayPaySlip(c);
    return 0;
}