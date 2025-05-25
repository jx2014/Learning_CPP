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

    std::cout << "\x34\x4D\n" << std::endl;
    std::cout << "\x34\t\x4D\n" << std::endl;

    return 0;

    
}

// https://cpp-primer.pages.dev/book/021-2.1._primitive_builtin_types.html