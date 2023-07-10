// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "orderedArr.h"
using namespace std;

int main()
{
    OrderedArray<int> arr(5, 1);


    arr.print();

    arr.clear();

    arr.print();

}