#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) {
        name = n;
    }
    void displayName() {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person {
public:
    Student() : Person("Unknown") {}
};

class Employee : virtual public Person {
public:
    Employee() : Person("Unknown") {}
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(string n) : Person(n) {}
};

int main() {
    TeachingAssistant t1("Raju");
    TeachingAssistant t2("Shyam");

    t1.displayName();
    t2.displayName();
    return 0;
}