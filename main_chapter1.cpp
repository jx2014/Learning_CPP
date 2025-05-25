#include <iostream>
#include "Sales_item.h"

// Chapter 1
int main()
{
    // 1.20 Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.
    // Sales_item item;
    // while (true) {
    //     std::cin >> item;
    //     if (item.isbn() == "") {
    //         break;
    //     }
    //     std::cout << item << std::endl;
    // }
    //
    // Exercise 1.21: Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.
    // Sales_item item1, item2, item_sum;
    // std::cin >> item1 >> item2;
    // if (item1.isbn() == item2.isbn()) {
    //     item_sum = item1 + item2;
    //     std::cout << item_sum << std::endl;
    // }
    //
    // Exercise 1.22: Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.
    // Sales_item item1, item2, item_sum;

    // std::cin >> item1;
    // item_sum = item1;
    // while (true) {
    //     std::cin >> item2;        
    //     if ( item1.isbn() == "" ) {
    //         break;
    //     }

    //     if (item1.isbn() == item2.isbn()) {
    //         item_sum += item2;
    //     } else {            
    //         std::cout << "Sum: " << item_sum << std::endl;
    //         item1 = item2;
    //         item_sum = item1;
    //     } 
    // }

    //Exercise 1.23: Write a program that reads several transactions and counts how many transactions occur for each ISBN.
    // Sales_item item1, item2;
    // uint32_t count = 1;
    
    // std::cin >> item1;
    // while (true) {
    //     if (item1.isbn() == "")
    //         break;
    //     std::cin >> item2;
    //     if (item1.isbn() == item2.isbn()) {
    //         count += 1;
    //     } else {
    //         std::cout << item1.isbn() << ": " << count << std::endl;
    //         item1 = item2;
    //         count = 1;
    //     }
    // }

    // Exercise 1.24: Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.
    // See previous solution

    // Exercise 1.25: Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this section.
    Sales_item total; // variable to hold data for the next transaction
    // read the first transaction and ensure that there are data to process
    if (std::cin >> total) {
        Sales_item trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (std::cin >> trans) {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn())
                total += trans; // update the running total
            else {
                // print results for the previous book
                std::cout << total << std::endl;
                total = trans;  // total now refers to the next book
            }
        }
        std::cout << total << std::endl; // print the last transaction
    } else {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }
    return 0;
}

// https://cpp-primer.pages.dev/book/016-1.6._the_bookstore_program.html