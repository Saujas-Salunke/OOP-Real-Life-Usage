#include <iostream>
using namespace std;

class Account {
private:
    double balance;
    friend class Auditor;
public:
    Account(double b) {
        balance = b;
    }
};

class Auditor {
public:
    void inspect(Account a) {
        cout << "Account Balance: " << a.balance << endl;
    }
};

int main() {
    Account acc(5000.0);
    Auditor aud;
    aud.inspect(acc);
    return 0;
}