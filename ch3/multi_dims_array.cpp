#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // From left to right
    // ia is of size 3;
    // - each element is an array of 4 int 
    // in 2-dim array, first dim is referred to as row; 2nd as column
    int ia0[3][4];
    // init all elements to 0
    int arr[10][20][30] = {0};

    // Init with values
    // - nested braces are optional, equivalent to 
    // - int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int ia[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    // - elements may be left out of initializer list
    // - e.g. init only 1st element of each row as follows
    // - in this case, nested braces are necessary
    int ia2[3][4] = {{0},{4},{8}};
    // - e.g. below init row 0; all others are init to 0
    int ia3[3][4] = {0,4,8};

    // Subscript multi-dim array
    // - e.g. assign 1st element of arr to the element of 3rd row, 4th col
    ia[2][3] = arr[0][0][0];
    // row is a ref to an array of int
    // row refers to 2nd row of ia
    int (&row)[4] = ia[1];

    // Use nested for loops to process elements in a mul-dim array
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia4[rowCnt][colCnt];
    for (size_t i = 0; i != rowCnt; ++i) {
        for (size_t j = 0; j != rowCnt; ++j) {
            ia4[i][j] = i * colCnt + j;
        }
    }

    // Use Range for
    // - the loop control var for all but innermost array must be reference
    size_t cnt = 0;
    // - if rwo is not a ref
    // - i.e., auto row:ia, then row is an array, i.e., a pointer to 1st element
    // - then in next loop, looping over a pointer is illegal
    for (auto &row: ia)
        for (auto &col: row) {
            col = cnt;
            ++ cnt;
        }

    // Pointer to multi-dim array
    // - ia[3][4] - ia has 3 element each of which is an array of 4 int
    // - p points to ia's first elment, i.e., an array of 4 int
    for (auto p = ia; p != ia+3; ++p)
        // q points to the 1st element of an array of 4 int
        for (auto q = *p; q != *p +4; ++q)
            cout << *q << ' ';
        cout << endl;

    // Rewrite above using begin and end
    for (auto p = begin(ia); p != end(ia); ++p)
        for (auto q = begin(*p); q != end(*p); ++q)
            cout << *q << ' ';
        cout << endl;


}