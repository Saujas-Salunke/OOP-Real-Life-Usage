#include <iostream>
#include <string>
using namespace std;

class University {
public:
    class Department {
    public:
        string name;
        Department(string n) {
            name = n;
        }
        void display() {
            cout << "Department: " << name << endl;
        }
    };
};

int main() {
    University::Department d1("Artificial Intelligence and Data Science");
    University::Department d2("Artificial Intelligence and Machine Learning");

    d1.display();
    d2.display();
    return 0;
}