#include <iostream>
#include "VisualStudio2012\1\Sales_item.h"
using namespace std;

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

int main()
{
	Sales_item item1, item2, item3;
	int transactions1{1}, transactions2{1}, transactions3{1};
	
	int n = 1;

	while (n<=3)
	{
		cout << "Enter ISBN, qty, price for item" << n << ": " << endl;
		if (n == 1)
			cin >> item1;
		if (n == 2)
			cin >> item2;
		if (n == 3)
			cin >> item3;

		n++;
	}

	cout << "isbn transactions" << endl;

	if (item1.isbn() == item2.isbn() && item1.isbn() == item3.isbn()) {
		transactions1 = 3;
		cout << item1.isbn() << " " << transactions1 << endl;
	}
	else if (item1.isbn() == item3.isbn()) {
		transactions1 = 2;
		cout << item1.isbn() << " " << transactions1 << endl;
		cout << item2.isbn() << " " << transactions2 << endl;
	}
	else if (item1.isbn() == item2.isbn()) {
		transactions1 = 2;
		cout << item1.isbn() << " " << transactions1 << endl;
		cout << item3.isbn() << " " << transactions3 << endl;
	}
	else if (item2.isbn() == item3.isbn()) {
		transactions2 = 2;
		cout << item1.isbn() << " " << transactions1 << endl;
		cout << item2.isbn() << " " << transactions2 << endl;
	}
	else
	{
		cout << item1.isbn() << " " << transactions1 << endl;
		cout << item2.isbn() << " " << transactions2 << endl;
		cout << item3.isbn() << " " << transactions3 << endl;
	}
	


	return 0;
}