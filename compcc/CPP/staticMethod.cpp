#include <bits/stdc++.h>
using namespace std;

class Base {
public:
    const static int staticV = 10;
    int non_staticV = 20;
    static void staticFunc() {
        cout << "staticFunc" << endl;
        cout << "static Variable: " << staticV << endl;
        cout << "Non-static Variable: " << non_staticV << endl;
    }
    void nonStaticFunc() {
        cout << "nonStaticFunc" << endl;
        cout << "static Variable: " << staticV << endl;
        cout << "Non-static Variable: " << non_staticV << endl;
    }
};


int main()
{
    Base obj;
    obj.nonStaticFunc();
    obj.staticFunc();
    return 0;
}
