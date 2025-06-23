#include <iostream>
#include <string>
#include "Sales_data.h"
 
int main() {
    
    Sales_data data1, data2;
    double price = 0;

    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;

    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo) {
        uint32_t totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenu = data1.revenue + data2.revenue;

        std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenu << " ";
        
        if (totalCnt != 0) 
            std::cout << totalRevenu / totalCnt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
    } else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }    

    return 0;
}

// https://cpp-primer.pages.dev/book/031-3.2._library_string_type.html