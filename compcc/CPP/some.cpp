#include <bits/stdc++.h>
using namespace std;

/*
int main()
{
    for (int N = 2; N <= 79; N++) {
        printf("\n----------------------\n");
        printf("N = %d\n", N);
        for (int fghij = 1234; fghij <= 98765 / N; fghij++) 
        {
            int abcde = fghij * N; // this way, abcde and fghij are at most 5 digits
            int tmp, used = (fghij < 10000); // if digit f=0, then we have to flag it
            tmp = abcde; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
            tmp = fghij; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
            if (used == (1<<10) - 1) // if all digits are used, print it
            printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
        }
        printf("\n----------------------\n");
    }

    return 0;
}
*/

/*
int main()
{
    int abcde = 98274;
    int fghij = 30561;
    int used = (fghij < 10000);
    cout << used << endl;
    int tmp;
    tmp = abcde; 
    while (tmp) 
    { 
        used |= 1 << (tmp % 10); 
        printf("used = %0.5d    digit = %d\n", used, tmp%10);
        tmp /= 10; 
    }
    tmp = fghij; 
    while (tmp) 
    { 
        used |= 1 << (tmp % 10); 
        printf("used = %0.5d    digit = %d\n", used, tmp%10);
        tmp /= 10; 
    }
    cout << used << endl;
    return 0;
}
*/

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

/*
int main()
{
    // Base* b = new Derived();
    Derived *d = new Derived();
    // Derived *d = new Base();
    // Base* b = d;
    // b->sample();
    d->sample();
    // d->~Base();
    d->~Derived();
    // b->~Base();
    // b->~Base();
    return 0;
}
*/



int main() {
 
int i = 2, j = 4, k = 8 ;
int *p = &i, *q = &j, *r = &k; 
 
k = i;
cout << i << j << k << *p << *q << *r << endl; 
 
p = q; 
cout << i << j << k << *p << *q << *r << endl;
 
*q = *r;
cout << i << j << k << *p << *q << *r << endl;
 
return 0;
}