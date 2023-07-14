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
		//Declare an array with default constructor
		cout <<"**************************************************"<<endl;
		cout <<"Array of integers declared with default constructor"<<endl;
		OrderedArray<int> array;
		cout << "The array size is: " << array.length() << endl;

		array.push(5);
		array.push(2);
		array.push(90);
		array.push(4);

		cout << endl;
		cout<<"Printing the array: "<<endl;
		cout << endl;

		array.print();

		cout << endl;
		cout << "The array size is: " << array.length() << endl;
		cout <<"\nThe array capacity is: "<<array.capacity()<<endl;
		cout << "\nThe element at index 2 is: " << array.getElement(2) << endl;
		cout << endl;
		cout << "**************************************************" << endl;
		cout << endl;

		//Declare an array with custom constructor
		cout<<"**************************************************"<<endl;
		cout << "Array of integers declared with custom constructor" << endl;
		OrderedArray<int> arr(5, 7);
		cout << "The array size is: " << arr.length() << endl;
		arr.push(6);
		arr.push(2);
		arr.push(2);
		arr.push(4);
		arr.push(13);
		
		cout << "The size of the array is: " << arr.length() << endl;
		arr.print();

		cout << "\nThe element at index 2 is: " << arr.getElement(2) << endl;

		arr.clear();
		cout << "\nThe size of the array after the clear function is: " << arr.length() << endl;
		arr.print();

		arr.push(2);
		arr.push(4);
		arr.push(1);
		arr.push(3);

		arr.print();
		cout << "\nThe sum of the first two elements of the array is " << arr.sumOfTwoElements();
		cout << endl;

		cout << "\narrayDoubles" << endl;
		OrderedArray<double> arr1(5, 1);
		arr1.push(6.4);
		arr1.push(2.3);
		arr1.push(2.1);
		arr1.print();
		cout<< "\nThe sum of the first two elements of the array is "<<arr1.sumOfTwoElements();

		cout<<"\nThe element at index 2 is: "<<arr1.getElement(2)<<endl;
		

		cout << "\narrayFloat" << endl;
		OrderedArray<float> arr2(5, 1);
		arr2.push(3.4f);
		arr2.push(1.3f);
		arr2.push(23.1f);
		arr2.print();
		cout << "\nThe sum of the first two elements of the array is " << arr2.sumOfTwoElements();

		OrderedArray<float> arr3(5, 1);
		arr3.push(3.4f);
		arr3.push(1.3f);
		arr3.push(24.1f);
	

		if(arr2==arr3)
			cout << "\narr and arr1 are equal" << endl;
		else
			cout << "\narr and arr1 are not equal" << endl;
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
	catch (out_of_range e){
		cout << e.what() << endl;
	}
	catch (...) {
		cout << "An error occurred" << endl;
	}
   
    


}