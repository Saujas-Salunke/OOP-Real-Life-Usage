#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class DataChecker {
public:
    bool checkMarks(int marks) const {
        if (marks >= 0 && marks <= 100)
            return true;
        return false;
    }

    bool checkAmount(double amount) const {
        if (amount > 0 && amount <= 1000000)
            return true;
        return false;
    }

    bool checkName(string name) const {
        if (name.empty())
            return false;

        for (char ch : name) {
            if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ')
                return false;
        }

        return true;
    }
};

int main() {
    DataChecker checker;

    cout << boolalpha;
    cout << "===== DATA CHECKER =====" << endl;

    cout << "Marks 88: "
         << checker.checkMarks(88) << endl;

    cout << "Marks -5: "
         << checker.checkMarks(-5) << endl;

    cout << "Amount Rs. 750000: "
         << checker.checkAmount(750000) << endl;

    cout << "Amount Rs. 1500000: "
         << checker.checkAmount(1500000) << endl;

    cout << "Name Rohan Deshmukh: "
         << checker.checkName("Rohan Deshmukh") << endl;

    cout << "Name Rohan99: "
         << checker.checkName("Rohan99") << endl;

    return 0;
}