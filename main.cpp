#include <iostream>
#include <string>
#include <iomanip> // for std::setw()
#include <cctype>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    // int i;
    // cout << "Enter a value for i: ";
    // cin >> i;
    // cout << i;

    // string s1;            // default initialization; s1 is the empty string
    // cout << "Enter a string for s1: ";
    // cin >> s1;
    // string s2 = s1;       // s2 is a copy of  s1
    // string s3 = "hiya";   // s3 is a copy of the string literal
    // string s4(10, 123);   // s4 is cccccccccc

    // cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;

    // string s1, s2;
    // cin >> s1 >> s2;
    // cout << s1 << s2 << endl;

    // string word;
    // while (cin >> word) 
    //     cout << word << endl;
    
    // string line;
    // auto len = line.size();
    // decltype(line.size()) punct_cnt = 0;

    // while (getline(cin, line)) {
    //     cout << "Size: " << std::setw(5) << line.size() << " ";
        
    //     // count the number of punctuation characters in s
    //     for (auto c : line)        // for every char in s
    //         if (ispunct(c))     // if the character is punctuation
    //             ++punct_cnt;    // increment the punctuation counter
    //     cout << std::setw(3) << punct_cnt
    //         << " punctuation characters in line: " << line << endl;
    //     punct_cnt = 0;
    // }


    // const string hexdigits = "0123456789ABCDEF";
    // cout << "Enter a series of numbers between 0 and 15"
    //  << " separated by spaces. Hit ENTER when finished: "
    //  << endl;
    // string result;
    // decltype(result.size()) n;
    // //string::size_type n;
    // while (cin >> n)
    //     if (n < hexdigits.size())
    //         result += hexdigits[n];
    // cout << "Your hex number is: " << result << endl;

    // exercise 3.10 remove all punctuations
    // string line;
    // auto len = line.size();

    // while (getline(cin, line)) {                
    //     for (auto c : line) {       // for every char in s
    //         if (!ispunct(c))     // if the character is punctuation
    //             cout << c;            
    //     }
    //     cout << endl;
    // }

// 3.3 Library vector Type
    // vector<int> v2(10, 42);     // 10 elements, each has value 42;
    // vector<int> v4{10};         // one element of value of 10;
    // vector<int> v5{10, 42};     // two elements, value of 10, and 42;
    // vector<string> v6{10};      // ten elements of null
    // vector<string> v7{10, "hi"}; // ten elements of "hi"

    // vector<int> v(10);
    // cout << v.size() << endl;
    // int n = 0;
    // for (auto &i : v) {
    //     n++;
    //     i = n * n;
    //     cout << i << " ";
    // }
    // cout << v[0] << " " << v[10] << endl;

    
    // Exercise 3.17: Read a sequence of words from cin and store the values a vector.
    // After you’ve read all the words, process the vector and change each word to uppercase. 
    // Print the transformed elements, eight words to a line.

    // string word;
    // vector<string> text;

    // cout << "Enter some sentences: ";
    // while (cin >> word) {
    //     text.push_back(word);
    //     if (cin.peek() == '\n') {
    //         cin.get();
    //         break;
    //     }

    // }

    // for (auto &w : text) {
    //     for (auto &l : w) {
    //         l = toupper(l);
    //     }
    // }

    // uint8_t n = 0;
    // for (auto &w : text) {
    //     cout << w << " ";
    //     n++;
    //     if (n == 7) {
    //         n = 0;
    //         cout << endl;
    //     }
    // }

    // Exercise 3.18
    // vector<int> ivec;
    // ivec[0] = 42; // incorrect, ivec size is 0
    // ivec.push_back(42); // one way to fix it.
    
    // Exercise 3.19: 
    //List three ways to define a vector and give it ten elements, each with the value 42. 
    // Indicate whether there is a preferred way to do so and why.
    // vector<int> ivec(10, 42);   // preferred
    // vector<int> ivec2;           // init w/ empty vector
    // for (int i = 0; i < 10; i++)    // use loop, convoluted.
    //     ivec2.push_back(42);
    // vector<int> ivec3(10);

    // Exercise 3.20: 
    // Read a set of integers into a vector. Print the sum of each pair of adjacent elements. 
    // Change your program so that it prints the sum of the first and last elements, 
    // followed by the sum of the second and second-to-last, and so on.
    // vector<int> ivec;
    // int num;

    // cout << "Enter some numbers: ";
    // while (cin >> num) {
    //     ivec.push_back(num);
    //     if (cin.peek() == '\n') {
    //         cin.get();
    //         break;
    //     }
    // }

    // cout << "Show sum of adjacenet values: \n";
    // for (decltype(ivec.size()) sz = 0;  sz < ivec.size(); sz=sz+2) {
    //     if ((sz + 1) >= ivec.size())
    //         break;        
    //     cout << ivec[sz] << " + " << ivec[sz+1] << " = " << ivec[sz] + ivec[sz+1] << endl;
    // }

    // cout << "Show sum of first and last numbers and so on...: \n";
    // for (decltype(ivec.size()) sz = 0;  sz < (ivec.size()-1-sz); sz++) {
    //     cout << ivec[sz] << " + " << ivec[ivec.size()-1-sz] << " = " << ivec[sz] + ivec[ivec.size()-1-sz] << endl;

    // }



    return 0;
}

// https://cpp-primer.pages.dev/book/032-3.3._library_vector_type.html