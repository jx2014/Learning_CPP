#include <iostream>

int main() {

    // unsigned u = 10;
    // int i = -42;
    // std::cout << i + i << std::endl;  // prints -84
    // std::cout << u + i << std::endl;  // if 32-bit ints, prints 4294967264

    // unsigned u1 = 42, u2 = 10;
    // std::cout << u1 - u2 << std::endl; // ok: result is 32
    // std::cout << u2 - u1 << std::endl; // ok: but the result will wrap around

    // for (unsigned u = 10; u > 0; --u)
    // std::cout << u << std::endl;

    // // Exercise 2.3: What output will the following code produce?
    // unsigned u = 10, u2 = 42;
    // std::cout << u2 - u << std::endl; // 32
    // std::cout << u - u2 << std::endl; // -32 = 4 294 967 264

    // int i = 10, i2 = 42;
    // std::cout << i2 - i << std::endl; // 32
    // std::cout << i - i2 << std::endl; // -32

    // std::cout << i - u << std::endl;  // 0
    // std::cout << u - i << std::endl;  // 0

    // std::cout << "hello \"\\t\":\t, \"\\a\":\a, \"\\v\":\v, \"\\b\":\b,\"\\n\":\n,\"\\r\":\r,\"\\f\":\f" << std::endl;

    // Exercise 2.8: Using escape sequences, write a program to print 2M followed by a newline. 
    //               Modify the program to print 2, then a tab, then an M, followed by a newline.

    // std::cout << "\x34\x4D\n" << std::endl;
    // std::cout << "\x34\t\x4D\n" << std::endl;

    // Exercise 2.9: Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.

    // (a)std::cin >> int input_value;

    // (b)int i = { 3.14 };

    // (c)double salary = wage = 9999.99;

    // (d)int i = 3.14;

    // Exercise 2.11: Explain whether each of the following is a declaration or a definition:

    // (a)extern int ix = 1024;    // declaration and definition

    // (b)int iy;                  // declaration and definition

    // (c)extern int iz;           // declaration

    // Exercise 2.12: Which, if any, of the following names are invalid?

    // (a)int double = 3.14;    // invalid

    // (b)int _;                // valid

    // (c)int catch-22;         // invalid

    // (d)int 1_or_2 = 1;       // invalid

    // (e)double Double = 3.14; // valid

    // Exercise 2.16: Which, if any, of the following assignments are invalid? If they are valid, explain what they do.

    // int i = 0, &r1 = i; double d = 0, &r2 = d;

    // r2 = 3.14159;
    // std::cout << d << std::endl;        // 3.14159

    // r2 = r1;
    // std::cout << r2 << " " << d << std::endl;       // 0 0
    
    // i = r2;
    // std::cout << i << " " << r1 << std::endl;    // 3 3

    // r1 = d;
    // std::cout << i << " " << r1 << std::endl;   // 3 3 

    // Exercise 2.17: What does the following code print?
    // int i, &ri = i;
    // i = 5; ri = 10;
    // std::cout << i << " " << ri << std::endl;   // 10 10

    // using namespace std;
    // int i = 42;
    // int &r = i;   // & follows a type and is part of a declaration; r is a reference
    // cout << &r << " " << r << " " << &i << " " << i << endl; // address, value, address, value
    // int *p;       // * follows a type and is part of a declaration; p is a pointer
    // p = &i;       // & is used in an expression as the address-of operator
    // cout << p << " " << *p << " " << i << " " << &i << endl; // address, value, value, address
    // *p = i;       // * is used in an expression as the dereference operator
    // int &r2 = *p; // & is part of the declaration; * is the dereference operator
    // cout << p << " " << *p << " " << r2 << " " << &r2 << endl; // address, value, value, address

    // Exercise 2.18: Write code to change the value of a pointer. Write code to change the value to which the pointer points.
    // int a = 123;
    // int *b = &a;
    // using namespace std;
    // cout << a << " " << b << " " << *b << endl; // 123, address, 123
    // *b = 1234;
    // cout << a << " " << b << " " << *b << endl; // 1234, address, 1234

    // Exercise 2.20: What does the following program do?
    // int i = 42;
    // int *p1 = &i;
    // *p1 = *p1 * *p1;
    // std::cout << i << " " << *p1 << " " << p1 << std::endl; // 42 1746 address

    // int i = 42;
    // int *p;  // Explicit initialization
    // int *&r = p;       // r is a reference to p
    // r = &i;            // p now points to i
    // *r = 0;            // i = 0

    // std::cout << "value of i (i)" << i << "\n"
    //           << "address of i (&i)" << &i << "\n"
    //           << "r (address stored in p, which is the address of i) = " << r << "\n"
    //           << "&r (address of p) = " << &r << "\n"
    //           << "p (value of p is address of i) " << p << " address of p (&p) " << &p << "\n"
    //           << "*r (value of i) = " << *r << std::endl;

    // Exercise 2.25: Determine the types and values of each of the following variables.

    // int* ip, &r = ip;   // ip is a pointer of int type,  r is an int reference of the address pointed by ip.

    // int i, *ip = 0;     // i is an integer,  ip is pointer of int type initalized with nullptr.

    // int* ip, ip2;       // ip is a pointer of int type, ip2 is an integer

    //2.4 const
    // int i = 42;
    // const int &r1 = i;      // we can bind a const int& to a plain int object
    // const int &r2 = 43;     // ok: r2 is a reference to const
    // const int &r3 = r1 * 2; // ok: r3 is a reference to const

    // std::cout << i  << " " << &i  << "\n"                 // 42, address of i
    //           << r1 << " " << &r1 << "\n"        // 42, address of r1 (same as address of i)
    //           << r2 << " " << &r2 << "\n"        // 42, address of r2
    //           << r3 << " " << &r3 << std::endl;  // 84, address of r3

    int x = 10, y = 20;
    int const *a = &x;
    a = &y;         // valid
    // *a = 30;      // invalid


    int *const b = &x;
    *b = 30;        // valid
    // b = &y          // invalid

    std::cout << x << " " << &x << "\n"
              << y << " " << &y << "\n"
              << a << " " << &a << *a << "\n"
              << b << " " << &b << *b << " " << x << std::endl;

    return 0;

    
}

https://cpp-primer.pages.dev/book/024-2.4._const_qualifier.html