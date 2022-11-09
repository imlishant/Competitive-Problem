#include <bits/stdc++.h>
using namespace std;

/*
class Base {
    public:
    Base() { cout << "Base Constructor\n";}
    // ~Base() { cout << "Base Destructor\n";}
    virtual ~Base() { cout << "Base Destructor\n";}
};

class Derived : public Base {
    public:
    Derived() { cout << "Derived Constructor\n";}
    ~Derived() { cout << "Derived Destructor\n";}
};

int main()
{
    Base* b = new Derived();
    delete(b);
    return 0;
}
*/

class Base {
public:
    Base() {cout << "Base Constructor\n";}
    virtual void sample() {cout << "Base sample\n";}
    virtual ~Base() { cout << "Base Destructor\n";}
};

class Derived : public Base {
public: 
    Derived() {cout << "Derived Constructor\n";}
    void sample() {cout << "Derived sample\n";}
    ~Derived() { cout << "Derived Destructor\n";}
};

int main()
{
    // Base* b = new Derived();
    // Derived *d = new Derived();
    // Derived *d = new Base();
    // Base* b = d;
    // b->sample();
    /*
    d->sample();
    d->~Base();
    d->sample();
    d->~Derived();
    d->sample();
    d->~Derived();
    d->sample();
    d->~Base();
    d->sample();
    */
    Base* ba = new Base();
    Base* b = new Derived();
    ba->sample();
    ba->~Base();
    b->sample();
    b->~Base();
    // b->~Base();
    // b->~Base();
    return 0;
}

// empty class is of size ONE.

/*
class NoVirtual {
  int a;
public:
  void x() const {}
  int i() const { return 1; }
};

class OneVirtual {
  int a;
public:
  virtual void x() const {}
  int i() const { return 1; }
};

class TwoVirtuals {
  int a;
public:
  virtual void x() const {}
  virtual int i() const { return 1; }
};

int main() {
  cout << "int: " << sizeof(int) << endl;
  cout << "NoVirtual: " << sizeof(NoVirtual) << endl;
  cout << "void* : " << sizeof(void*) << endl;
  cout << "OneVirtual: " << sizeof(OneVirtual) << endl;
  cout << "TwoVirtuals: " << sizeof(TwoVirtuals) << endl;
}
*/

/*
class Base 
{
public:
    void f1();
    virtual void f2();
    virtual void f3() = 0;
};

class Derived : public Base 
{
public:
    void f2();
    // void f3();
    void f4();
};

int main()
{
    Base b; 
    Derived d;

    return 0;
}
*/