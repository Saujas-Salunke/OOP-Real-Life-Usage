#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Student {
private:
    int rollNo;
    string name;
    double marks;

public:
    // Default constructor
    Student() : rollNo(0), marks(0.0) {}

    // Parameterized constructor
    Student(int r, string n, double m) 
        : rollNo(r), name(n), marks(m) {}

    // Save student data to file
    void saveToFile(ofstream& out) const {
        out << rollNo << ',' << name << ',' << marks << '\n';
    }

    // Load student data from a line of text
    bool loadFromLine(const string& line) {
        string rollText;
        string nameText;
        string marksText;
        stringstream stream(line);

        if (!getline(stream, rollText, ',')) return false;
        if (!getline(stream, nameText, ',')) return false;
        if (!getline(stream, marksText)) return false;

        rollNo = stoi(rollText);
        name = nameText;
        marks = stod(marksText);

        return true;
    }

    // Display student information
    void display() const {
        cout << "Roll: " << rollNo 
             << " | Name: " << name 
             << " | Marks: " << marks << endl;
    }
};

int main() {
    // === Writing to File ===
    ofstream outFile("students.csv");
    
    if (!outFile) {
        cerr << "Unable to open students.csv for writing." << endl;
        return 1;
    }

    Student s1(101, "Rahul Patil", 85.5);
    Student s2(102, "Priya Sharma", 92.0);
    Student s3(103, "Amit Kulkarni", 78.5);

    s1.saveToFile(outFile);
    s2.saveToFile(outFile);
    s3.saveToFile(outFile);
    outFile.close();

    // === Reading from File ===
    ifstream inFile("students.csv");
    
    if (!inFile) {
        cerr << "Unable to open students.csv for reading." << endl;
        return 1;
    }

    cout << "=== Student Report ===" << endl;
    string line;
    
    while (getline(inFile, line)) {
        Student student;
        if (student.loadFromLine(line)) {
            student.display();
        }
    }

    inFile.close();

    return 0;
}