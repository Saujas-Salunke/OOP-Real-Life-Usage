#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    Person(string n) {
        name = n;
    }
    void displayName() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
public:
    int rollNumber;
    Student(string n, int r) : Person(n) {
        rollNumber = r;
    }
    void displayStudent() {
        displayName();
        cout << "Roll Number: " << rollNumber << endl;
    }
};

int main() {
    Student s1("Bob", 202);
    Student s2("Jack", 500);

    s1.displayStudent();
    s2.displayStudent();

    return 0;
}