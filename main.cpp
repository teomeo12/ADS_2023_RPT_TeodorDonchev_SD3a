// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "orderedArr.h"
using namespace std;

int main()
{
    try
    {
		//Question 1
		OrderedArray<int> arr(0, 7);
		arr.push(6);
		arr.push(2);
		arr.push(2);
		arr.push(4);
		arr.push(13);


		cout << "The size of the array is: " << arr.length() << endl;
		arr.print();

		arr.clear();
		cout << "\nThe size of the array after the clear function is: " << arr.length() << endl;
		arr.print();

		arr.push(2);
		arr.push(4);
		arr.push(1);

		arr.push(3);

		arr.print();

		cout << "\narrayDoubles" << endl;
		OrderedArray<double> arr1(5, 1);
		arr1.push(6.4);
		arr1.push(2.3);
		arr1.push(2.1);
		arr1.print();

		cout << "\narrayFloat" << endl;
		OrderedArray<float> arr2(5, 1);
		arr2.push(3.4f);
		arr2.push(1.3f);
		arr2.push(23.1f);
		arr2.print();

    }
    catch (invalid_argument e)
    {
		cout << e.what() << endl;
    }
    catch (int e)
    {
		cout << "An int exception occurred" << endl;
    }
    catch (double d)
    {
    }
	catch (logic_error){
		cout << "An LOGIC error occurred" << endl;
	}
	catch (...) {
		cout << "An error occurred" << endl;
	}
   
    


}