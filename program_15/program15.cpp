#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string registrationNumber;
    double ratePerDay;
public:
    Vehicle(string reg, double rate) {
        registrationNumber = reg;
        ratePerDay = rate;
    }
    virtual double calculateRent(int days) {
        return ratePerDay * days;
    }
    virtual void display() {
        cout << "Registration: " << registrationNumber << endl;
        cout << "Rate per day: " << ratePerDay << endl;
    }
};

class Car : public Vehicle {
public:
    int numberOfDoors;
    Car(string reg, double rate, int doors) : Vehicle(reg, rate) {
        numberOfDoors = doors;
    }
    void display() override {
        Vehicle::display();
        cout << "Doors: " << numberOfDoors << endl;
    }
};

class Bike : public Vehicle {
public:
    int engineCapacity;
    Bike(string reg, double rate, int capacity) : Vehicle(reg, rate) {
        engineCapacity = capacity;
    }
    double calculateRent(int days) override {
        return ratePerDay * days * 0.9;
    }
    void display() override {
        Vehicle::display();
        cout << "Engine Capacity: " << engineCapacity << " cc" << endl;
    }
};

int main() {
    Car car("MH12AB1234", 1500.0, 5);
    Bike bike("MH12CD5678", 500.0, 150);

    cout << "Car Details" << endl;
    car.display();
    cout << "Rent for 3 days: " << car.calculateRent(4) << endl;

    cout << endl;

    cout << "Bike Details" << endl;
    bike.display();
    cout << "Rent for 3 days: " << bike.calculateRent(4) << endl;
    return 0;
}