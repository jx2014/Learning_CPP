#include <iostream>
#include "Sales_item.h"
int main()
{
    // 1.20 Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.
    Sales_item item;
    while (true) {
        std::cin >> item;
        if (item.isbn() == "") {
            break;
        }
        std::cout << item << std::endl;
    }

    return 0;
}

// https://cpp-primer.pages.dev/book/015-1.5._introducing_classes.html