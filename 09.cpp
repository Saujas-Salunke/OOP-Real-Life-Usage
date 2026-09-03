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
};

class Student : public Person {
public:
    int rollNumber;
    Student(string n, int r) : Person(n) {
        rollNumber = r;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
};

int main() {
    Student s1("Arthur", 24);
    Student s2("Harley", 26);

    s1.display();
    s2.display();
    
    return 0;
}