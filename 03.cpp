#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base public function" << endl;
    }
};

class PublicDerived : public Base {
};

class PrivateDerived : private Base {
public:
    void callBaseShow() {
        show();
    }
};

int main() {
    PublicDerived p;
    p.show();

    PrivateDerived q;
    q.callBaseShow();
    return 0;
}