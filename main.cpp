// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "orderedArr.h"
using namespace std;

int main()
{
    OrderedArray<int> arr(5, 1);
    arr.push(6);
    arr.push(2);
    arr.push(2);
    arr.push(4);
    arr.push(1);


    cout<<"The size of the array is: "<<arr.length() << endl;
    arr.print();

    arr.clear();
    cout << "\nThe size of the array after the clear function is: " << arr.length() << endl;
    arr.print();

    arr.push(2);
    arr.push(4);
    arr.push(1);

    arr.push(3);

    arr.print();
    

}