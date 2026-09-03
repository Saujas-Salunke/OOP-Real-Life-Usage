#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
};

class Rectangle : public Shape {
public:
    double length, width;
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    double area() override {
        return length * width;
    }
};

class Circle : public Shape {
public:
    double radius;
    Circle(double r) {
        radius = r;
    }
    double area() override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Rectangle r(6.0, 3.0);
    Circle c(5.0);

    cout << "Rectangle Area: " << r.area() << endl;
    cout << "Circle Area: " << c.area() << endl;
    return 0;
}