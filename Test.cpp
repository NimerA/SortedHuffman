#include "Test.h"


void test()
{

    static const char arrx[] = {'x', 'y', 'z'};
    vector<char> vecx (arrx, arrx + sizeof(arrx) / sizeof(arrx[0]) );

    static const int arr2x[] = {5, 10, 15,};
    vector<int> vec2x (arr2x, arr2x + sizeof(arr2x) / sizeof(arr2x[0]) );

    map<char,string> resx = getHuffman(vecx, vec2x);

    static const char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<char> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    static const int arr2[] = {5, 10, 12, 13, 19, 91};
    vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

    map<char,string> res = getHuffman(vec, vec2);

    if(res['f'] == "1"
       && res['c'] == "000"
       && res['d'] == "001"
       && res['a'] == "0100"
       && res['b'] == "0101"
       && res['e'] == "011"

       && resx['x'] == "00"
       && resx['y'] == "01"
       && resx['z'] == "1")
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
