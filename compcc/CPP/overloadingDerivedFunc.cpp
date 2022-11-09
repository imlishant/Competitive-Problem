#include <bits/stdc++.h>
using namespace std;


class Base 
{
public:
    void f(int i) {cout << "f(int) : " << i+1 << endl;}
};

class Derived : public Base 
{
public:
    using Base::f; // brings all (f) to OVERLOAD;
    void f(double d) {cout << "f(double) : " << d+1.3 << endl;}
};

int main()
{
    // Base* b = new Base();
    // Derived* d = new Derived();
    // Base* d = new Derived();
    Base* d = new Base();
    // Derived* d = new Base();

    // b->f(3);
    d->f(3);
    d->f(3.2);

    return 0;
}