#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // 2 statements that allow for conditional execution
    // -  if statement
    // -  switch statement

    vector<string> scores = {"F","D","C","B","A","A++"};
    int grade;
    string lettergrade;

    if (grade < 60)
        lettergrade = scores[0];
    else {
        lettergrade = scores[(grade - 50)/10];
        // if not already A++
        if (grade != 100)
            // grade ends in 8 orr9 get a +
            // ending in 0, 1, or 2 get a -
            if (grade % 10 > 7)
                lettergrade += '+';
            else {
                if (grade % 10 < 3)
                lettergrade += '-';
            }
    }

    // switch statement
    // a progrm to count vowel
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch) {
        // if the expr of switch(expr) matches a case label
        // - execution begins with the 1st statement following that label
        // - continues normally from that through end of switch or 
        // - until a break statement

        // - always use a break statement at the end of a case, comment if otherwise
        switch(ch) {
            // case labels must be integral constant expressions
            // 3.14 is doulbe, not integral
            // case 3.14:
                // break;
            // ival is nonconstant
            // case ival:
            //     break;
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
        }
    }
    // print
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << endl;

    // count total number of vowels
    unsigned vowelCnt = 0, otherCnt = 0;
    while ( cin >> ch) {
        switch(ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            // or simply and legally
            // case 'a': case 'e': case 'i': case 'o': case 'u': 
                ++vowelCnt;
                break;
            // default labe is executed when no case label matches the swithc expr
            default:
                ++otherCnt;
                break;
        }
    }
}