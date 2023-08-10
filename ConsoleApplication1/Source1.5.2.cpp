#include <iostream>
#include "VisualStudio2012\1\Sales_item.h"
using namespace std;

// chapter 1.5
// 
// Example of 1.5.2
//int main()
//{
//    Sales_item item1, item2;
//    std::cin >> item1 >> item2;
//    // first check that item1 and item2 represent the same book
//    if (item1.isbn() == item2.isbn()) {
//        std::cout << item1 + item2 << std::endl;
//        return 0;   // indicate success
//    }
//    else {
//        std::cerr << "Data must refer to same ISBN"
//            << std::endl;
//        return -1;  // indicate failure
//    }
//}

// Exercise 1.23 and 1.24
// reads several transactions and counts how many transactions occur for each ISBN.



//int main()
//{
//	Sales_item item1, item2, item3;
//	int transactions1{1}, transactions2{1}, transactions3{1};
//	
//	int n = 1;
//
//	while (n<=3)
//	{
//		cout << "Enter ISBN, qty, price for item" << n << ": " << endl;
//		if (n == 1)
//			cin >> item1;
//		if (n == 2)
//			cin >> item2;
//		if (n == 3)
//			cin >> item3;
//
//		n++;
//	}
//
//	cout << "isbn transactions" << endl;
//
//	if (item1.isbn() == item2.isbn() && item1.isbn() == item3.isbn()) {
//		transactions1 = 3;
//		cout << item1.isbn() << " " << transactions1 << endl;
//	}
//	else if (item1.isbn() == item3.isbn()) {
//		transactions1 = 2;
//		cout << item1.isbn() << " " << transactions1 << endl;
//		cout << item2.isbn() << " " << transactions2 << endl;
//	}
//	else if (item1.isbn() == item2.isbn()) {
//		transactions1 = 2;
//		cout << item1.isbn() << " " << transactions1 << endl;
//		cout << item3.isbn() << " " << transactions3 << endl;
//	}
//	else if (item2.isbn() == item3.isbn()) {
//		transactions2 = 2;
//		cout << item1.isbn() << " " << transactions1 << endl;
//		cout << item2.isbn() << " " << transactions2 << endl;
//	}
//	else
//	{
//		cout << item1.isbn() << " " << transactions1 << endl;
//		cout << item2.isbn() << " " << transactions2 << endl;
//		cout << item3.isbn() << " " << transactions3 << endl;
//	}
//	
//
//
//	return 0;
//}

// chapter 1.6
//#include <iostream>
//#include "VisualStudio2012\1\Sales_item.h"
//
//int main()
//
//{
//
//    Sales_item total; // variable to hold data for the next transaction
//
//    // read the first transaction and ensure that there are data to process
//
//    if (std::cin >> total) {
//
//        Sales_item trans; // variable to hold the running sum
//
//        // read and process the remaining transactions
//
//        while (std::cin >> trans) {
//
//            // if we're still processing the same book
//            if (total.isbn() == trans.isbn())
//                total += trans; // update the running total
//            else {
//                // print results for the previous book
//                std::cout << total << std::endl;
//                total = trans;  // total now refers to the next book
//            }
//        }
//        std::cout << total << std::endl; // print the last transaction
//    }
//    else {
//
//        // no input! warn the user
//        std::cerr << "No data?!" << std::endl;
//        return -1;  // indicate failure
//    }
//
//    return 0;
//
//}

// §2.1.2
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main() {
	unsigned u = 10, u1 = 42, u2 = 1000;
	int i = -42;
	cout << i + i << endl;
	cout << i + u << endl;
	cout << u1 - u2 << endl;
	cout << u2 - u1 << endl;

	for (i = 10; i >= 0; --i)
		cout << i << endl;


	/*for (u = 10; u >= 0; ++u)
		cout << u << endl;*/

	u = 10;
	cout << "u: " << u << endl;	
	cout << "--u: " << --u << endl;
	cout << "u: " << u << endl;
	cout << "u--: " << u-- << endl;
	cout << "u: " << u << endl;

	for (u = 10; u > 0; --u) {
		cout << u << endl;
		//_getch();
	}

	cout << "Reset u to 10." << endl;
	u = 10;
	while (u > 0) {
		cout << --u << endl;		
	}

	// unsigned
	u = 10;
	u2 = 42;
	std::cout << u2 - u << std::endl;	// 32
	std::cout << u - u2 << std::endl;	// 4,294,967,264


	// signed
	i = 10;
	int i2 = 42;
	std::cout << i2 - i << std::endl;	// 32
	std::cout << i - i2 << std::endl;	// -32

	std::cout << i - u << std::endl;	// 0
	std::cout << u - i << std::endl;	// 0

	// Exercise 2.4

	return 0;
}


