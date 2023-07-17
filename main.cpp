// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "orderedArr.h"

using namespace std;

void demoDeclareArraywithDefaultConstructor();
void demoDeclareArraywithCustomConstructor();
void demoArrayofDoublesCustomConstructor();
void demoArrayofFloatsCustomConstructor();
int main()
{
    try
    {
		//Question 1
		//Demo of Declare an array with default constructor
		demoDeclareArraywithDefaultConstructor();


		//Declare an array with custom constructor
		demoDeclareArraywithCustomConstructor();
	
		//Array of doubles with custom constructor
		demoArrayofDoublesCustomConstructor();
	
		//Array of floats with custom constructor
		demoArrayofFloatsCustomConstructor();


		cout << "****************************************************" << endl;
		cout << "Comparising arrays" << endl;
		cout << "****************************************************" << endl;

		OrderedArray<float> arr1(1);
		arr1.push(3.4f);
		arr1.push(1.3f);
		arr1.push(24.1f);

		OrderedArray<float> arr2(1);
		arr2.push(3.4f);
		arr2.push(1.3f);
		arr2.push(24.1f);

		if(arr1==arr2)
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

void demoDeclareArraywithDefaultConstructor() {
	//Declare an array with default constructor
	cout << "**********************************************************" << endl;
	cout << "Initializing array of integers with default constructor" << endl;
	cout << "**********************************************************" << endl;

	OrderedArray<int> array;
	cout << endl;
	cout << "The array size is: " << array.length() << endl;
	cout << "The array capacity is: " << array.capacity() << endl;
	cout << "The array grow size is: " << array.getGrowSize() << endl;
	cout << "Printing the array: " << endl;
	cout << endl;

	array.print();
	cout << endl;
	cout << "*===================================================*" << endl;
	cout << "Array of integers" << endl;
	array.push(5);
	array.push(2);
	array.push(90);
	array.push(4);

	cout << endl;
	cout << "Printing the array: " << endl;
	cout << endl;

	array.print();

	cout << endl;
	cout << "The array size is: " << array.length() << endl;
	cout << "The array capacity is: " << array.capacity() << endl;
	cout << "The array grow size is: " << array.getGrowSize() << endl;
	cout << "Adding 7 more elements to the array:" << endl;

	array.push(1);
	array.push(3);
	array.push(7);
	array.push(8);
	array.push(9);
	array.push(10);
	array.push(11);

	cout << endl;
	cout << "Printing the array: " << endl;
	cout << endl;

	array.print();

	cout << endl;
	cout << "The array size is: " << array.length() << endl;
	cout << "The array capacity is: " << array.capacity() << endl;
	cout << "The array grow size is: " << array.getGrowSize() << endl;
	cout << "The element at index 2 is: " << array.getElement(2) << endl;
	cout << endl;

	cout << "please enter a value " << endl;
	int elementValueInt;
	cin >> elementValueInt;
	cout << "The value " << elementValueInt << " is at possition: " << array.search(elementValueInt) << endl;
	cout << "**************************************************" << endl;
	cout << "End of default constructor" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

void demoDeclareArraywithCustomConstructor() {
	//Declare an array with custom constructor
	cout << "**************************************************" << endl;
	cout << "Initializing array of integers with custom constructor" << endl;
	cout << "**************************************************" << endl;

	OrderedArray<int> arr(1);
	cout << endl;
	cout << "The array size is: " << arr.length() << endl;
	cout << "The array capacity is: " << arr.capacity() << endl;
	cout << "The array grow size is: " << arr.getGrowSize() << endl;
	cout << "Printing the array: " << endl;
	cout << endl;

	arr.print();
	cout << endl;

	cout << "*----------------------------------------------*" << endl;
	cout << "Array of integers " << endl;
	arr.push(6);
	arr.push(2);
	arr.push(2);
	arr.push(4);
	arr.push(13);

	cout << endl;
	cout << "Printing the array: " << endl;
	cout << endl;

	arr.print();
	cout << endl;
	cout << "The array size is: " << arr.length() << endl;
	cout << "\nThe array capacity is: " << arr.capacity() << endl;
	cout << "\nThe array grow size is: " << arr.getGrowSize() << endl;

	arr.clear();
	cout << "\nClear function is called: " << endl;
	cout << "*----------------------------------------------*" << endl;
	cout << endl;
	cout << "Printing the array: " << endl;
	cout << endl;

	arr.print();

	cout << endl;
	cout << "The array size is: " << arr.length() << endl;
	cout << "The array capacity is: " << arr.capacity() << endl;
	cout << "The array grow size is: " << arr.getGrowSize() << endl;

	cout << endl;
	cout << "*----------------------------------------------*" << endl;
	cout << "Adding 4 elements to the array" << endl;

	arr.push(2);
	arr.push(4);
	arr.push(1);
	arr.push(3);

	cout << endl;
	cout << "Printing the array: " << endl;
	cout << endl;

	arr.print();
	cout << endl;
	cout << "The element at index 3 is: " << arr.getElement(3) << endl;
	cout << "The sum of the first two elements of the array is " << arr.sumOfTwoElements();
	cout << endl;
	cout << "**************************************************" << endl;
	cout << "End of custom constructor" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

void demoArrayofDoublesCustomConstructor(){

	cout << "**************************************************" << endl;
	cout << "Initializing array of doubles with custom constructor" << endl;
	cout << "**************************************************" << endl;

	OrderedArray<double> arr1(5);
	cout << endl;
	cout << "The array size is: " << arr1.length() << endl;
	cout << "The array capacity is: " << arr1.capacity() << endl;
	cout << "The array grow size is: " << arr1.getGrowSize() << endl;
	cout << "Printing the array: " << endl;
	cout << endl;
	arr1.print();
	cout << endl;

	cout << "*----------------------------------------------*" << endl;
	cout << "Array of doubles " << endl;
	arr1.push(6.4);
	arr1.push(2.3);
	arr1.push(2.1);
	arr1.push(4.5);
	arr1.push(13.2);
	cout << endl;
	cout << "Printing the array: " << endl;
	cout << endl;

	arr1.print();
	cout << endl;
	cout << "The array size is: " << arr1.length() << endl;
	cout << "The array capacity is: " << arr1.capacity() << endl;
	cout << "The array grow size is: " << arr1.getGrowSize() << endl;
	cout << "Printing the array: " << endl;
	cout << "The sum of the first two elements of the array is " << arr1.sumOfTwoElements() << endl;
	cout << "The element at index 2 is: " << arr1.getElement(2) << endl;

	cout << "*----------------------------------------------*" << endl;
	cout << "\nRemove two elements form the array" << endl;

	arr1.remove(2);
	arr1.remove(3);

	cout << "The array size is: " << arr1.length() << endl;
	cout << "The array capacity is: " << arr1.capacity() << endl;
	cout << "The array grow size is: " << arr1.getGrowSize() << endl;
	cout << "Printing the array: " << endl;
	cout << endl;
	arr1.print();
	cout << endl;
	cout << "*----------------------------------------------*" << endl;
	cout << "Adding 4 elements to the array" << endl;

	arr1.push(34.5);
	arr1.push(23.6);
	arr1.push(12.7);
	arr1.push(13.8);
	cout << "Printing the array: " << endl;
	cout << endl;
	arr1.print();
	cout << endl;

	cout << "Removing element out of array range" << endl;
	try {
		arr1.remove(10);
	}
	catch (out_of_range e) {
		cout << e.what() << endl;
	}

	cout << "**************************************************" << endl;
	cout << "End of Array of doubles with custom constructor" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

void demoArrayofFloatsCustomConstructor() {
	cout << "****************************************************" << endl;
	cout << "Initializing array of floats with custom constructor" << endl;
	cout << "****************************************************" << endl;

	OrderedArray<float> arr2(5);
	cout << endl;
	cout << "The array size is: " << arr2.length() << endl;
	cout << "The array capacity is: " << arr2.capacity() << endl;
	cout << "The array grow size is: " << arr2.getGrowSize() << endl;
	cout << "Printing the array: " << endl;
	cout << endl;
	arr2.print();
	cout << endl;

	cout << "*----------------------------------------------*" << endl;
	cout << "Array of floats " << endl;
	arr2.push(3.4f);
	arr2.push(1.3f);
	arr2.push(24.1f);
	arr2.push(12.5f);

	cout << endl;
	cout << "Printing the array: " << endl;
	cout << endl;

	arr2.print();
	cout << endl;

	cout << "The array size is: " << arr2.length() << endl;
	cout << "The array capacity is: " << arr2.capacity() << endl;
	cout << "The array grow size is: " << arr2.getGrowSize() << endl;
	cout << "Printing the array: " << endl;
	cout << "The sum of the first two elements of the array is " << arr2.sumOfTwoElements() << endl;
	cout << "The element at index 2 is: " << arr2.getElement(2) << endl;

	cout << "\nRemove an element form the array" << endl;

	arr2.remove(2);
	arr2.print();


	cout << "*----------------------------------------------*" << endl;
	cout << "\nSearch an element in the array" << endl;

	cout << "please enter a value " << endl;
	float elementValueFloat;
	cin >> elementValueFloat;
	cout << "The value " << elementValueFloat << " is at possition: " << arr2.search(elementValueFloat) << endl;


	cout << "**************************************************" << endl;
	cout << "End of Array of floats with custom constructor" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}