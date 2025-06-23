#include <iostream>
#include <string>
#include <iomanip> // for std::setw()
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

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
    string line;
    auto len = line.size();

    while (getline(cin, line)) {                
        for (auto c : line) {       // for every char in s
            if (!ispunct(c))     // if the character is punctuation
                cout << c;            
        }
        cout << endl;
    }

    return 0;
}