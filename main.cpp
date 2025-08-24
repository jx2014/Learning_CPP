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

class Screen {
    public:        
        typedef std::string::size_type pos;
        Screen() = default;
        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}
        char get() const { return  contents[cursor]; }
        inline char get(pos ht, pos wd) const;
        Screen move(pos r, pos c);
        Screen set(char);
        Screen set(pos, pos, char);
        Screen display(std::ostream &os) { do_display(os); return *this; }
        const Screen &display(std::ostream &os) const { do_display(os); return *this; }
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
        void do_display(std::ostream &os) const {os << contents;}
};

inline Screen Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen Screen::set(pos r, pos col, char ch) {
    contents[r*width + col] = ch;
    return *this;
}

inline Screen Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}



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
    // vector<string> text{};

    // for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
    //     cout << *it << endl;

// Exercise 3.23: 
    // Write a program to create a vector with ten int elements. 
    // Using an iterator, assign each element a value that is twice its current value. 
    // Test your program by printing the vector.

    // vector<int> a{1,2,3,4,6,7,8,9,10};

    // for (decltype(a.size()) sz = 0;  sz < a.size(); sz++) {
    //     cout << a[sz] << " ";
    // }
    // cout << endl;

    // for (auto it=a.begin(); it!=a.end(); it++) {    
    //     *it = (*it) * 2;
    // }

    // for (decltype(a.size()) sz = 0;  sz < a.size(); sz++) {
    //     cout << a[sz] << " ";
    // }
    // cout << endl;

// Binary search using iterator:
    // // text must be sorted
    // // beg and end will denote the range we're searching
    // auto beg = text.begin(), end = text.end();
    // auto mid = text.begin() + (end - beg)/2; // original midpoint
    // // while there are still elements to look at and we haven't yet found sought
    // while (mid != end && *mid != sought) {
    //     if (sought < *mid)     // is the element we want in the first half?
    //         end = mid;         // if so, adjust the range to ignore the second half
    //     else                   // the element we want is in the second half
    //         beg = mid + 1;     // start looking with the element just after mid
    //     mid = beg + (end - beg)/2;  // new midpoint, not using (beg + end) / 2 to avoid integer overflow
    // }


// Exercise 3.25: Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.
    // Original p. 104
    // count the number of grades by clusters of ten: 0--9, 10--19, . .. 90--99, 100
    // vector<unsigned> scores(11); // 11 buckets, all initially 0
    // vector<unsigned> grade{42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93};
    // for (decltype(grade.size()) i=0; i<grade.size(); i++) {
    //     if (grade[i] <= 100)       // handle only valid grades
    //         ++scores[grade[i]/10]; // increment the counter for the current cluster
    // }

    // for (decltype(scores.size()) i=0; i<scores.size(); i++)
    //     cout << scores[i] << " ";
    // cout << endl;  
    
    // Rewrite using iterators
    // vector<unsigned> scores(11); // 11 buckets, all initially 0
    // vector<unsigned> grade{42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93};

    // for (auto i = grade.begin(); i < grade.end(); i++) {
    //     if (*i <= 100) {             // handle only valid grades
    //         auto s = scores.begin() + (*i) / 10; 
    //         (*s)++;
    //     }
    // }

    // for (auto i = scores.cbegin(); i < scores.cend(); i++)
    //     cout << *i << " ";

// Exercise 3.24: Redo the last exercise from § 3.3.3 (p. 105) using iterators.
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
    // for (auto i = ivec.cbegin();  i < ivec.cend(); i+=2) {
    //     if ( (i + 1) >= ivec.cend())
    //         break;        
    //     cout << *i << " + " << *(i+1) << " = " << *i + *(i+1) << endl;
    // }

    // // take note where a and b is initially.     
    // cout << "Show sum of first and last numbers and so on...: \n";
    // for (auto a = ivec.cbegin(), b = ivec.cend()-1; a < b; a++, b-- ) {
    //     cout << *a << " + " << *b << " = " << (*a) + (*b) << endl;
    // }

    // vector<string> text{};

    // for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
    //     cout << *it << endl;

// Exercise 3.26
    // mid = beg + (end - beg) / 2; instead of mid = (beg + end) / 2, the second case can cause overflow when adding beg and end.


// 3.5 Arrays
    // If you don’t know exactly how many elements you need, use a vector.

    // int arr[10];                // an array of 10 integers
    // int *ptrs[10];              // ptrs is an array of ten pointers to int
    // int (*Parray)[10] = &arr;   // Parray points to an array of ten ints.
    // int (&arrRef)[10] = arr;    // arrRef is an reference, it refers an array of ten ints.

    // count the number of grades by clusters of ten: 0--9, 10--19, ... 90--99, 100
    // unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
    // unsigned grade;

    // // count the number of grades by clusters of ten: 0--9, 10--19, ... 90--99, 100
    // unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
    // unsigned grade;
    // while (cin >> grade) {
    //     if (grade <= 100)
    //         ++scores[grade/10]; // increment the counter for the current cluster
    // }
    
    // Exercise 3.31: Write a program to define an array of ten ints. 
    // Give each element the same value as its position in the array.

    // const int8_t arraySize = 10;
    // int intArray[arraySize];
    // for (int8_t i = 0; i < arraySize; i++ ) {
    //     intArray[i] = i;
    // }

    // // Exercise 3.32: Copy the array you defined in the previous exercise into another array.
    // // Rewrite your program to use vectors.

    // std::vector<int> intVector(std::begin(intArray), std::end(intArray));

    // Using pointers to loop through the printing the elements in arr as follows:
    // int arr[] = {0,1,2,3,4,5,6,7,8,9};
    // int *e = &arr[10]; // pointer just past the last element in arr
    // for (int *b = arr; b != e; ++b)
    // cout << *b << endl; // print the elements in arr

    Screen myScreen(5, 3, 'x');
    const Screen blank(5, 3, 'y');
    myScreen.move(3,0).set('#').move(1,0).set('X').display(cout);
    cout << endl;
    blank.display(cout);

    return 0;
}







// https://cpp-primer.pages.dev/book/075-7.3._additional_class_features.html