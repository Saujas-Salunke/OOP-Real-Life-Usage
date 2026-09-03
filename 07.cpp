#include <iostream>
using namespace std;

class Academic {
public:
    void display() {
        cout << "Academic information" << endl;
    }
};

class Sports {
public:
    void display() {
        cout << "Sports information" << endl;
    }
};

class Student : public Academic, public Sports {
public:
    void displayAll() {
        Academic::display();
        Sports::display();
    }
};

int main() {
    Student s;
    s.Academic::display();
    s.Sports::display();
    s.displayAll();
    return 0;
}