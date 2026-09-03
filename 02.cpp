#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
public:
    Employee(string n) {
        name = n;
    }
};

class Developer : public Employee {
public:
    string language;
    Developer(string n, string l) : Employee(n) {
        language = l;
    }
    void display() {
        cout << "Developer: " << name << endl;
        cout << "Language: " << language << endl;
    }
};

int main() {
    Developer d1("Shinosuke", "C++");
    Developer d2("Kazama", "Python");

    d1.display();
    d2.display();
    return 0;
}