// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "orderedArr.h"
#include "MySet.h"
#include <fstream>


void arrayWithDefaultConstructor();
void orderedArrayWithCustomConstructor();
void orderedArrayOfDoublesCustomConstructor();
void orderedArrayOfFloatsCustomConstructor();
void orderedArrayOfLongsCustomConstructor();
void compareEqualArrays();
void compareNotEqualArrays();
void compareGreatThanArray();
void compareLessThanArray();
void compareGreatThanEqualArray();
void compareLessThanEqualArray();
void declareSetsOfIntegersDefaultConstructor();
void declareSetsOfDoublesCustomConstructor();
void leads();


int main()
{
	using std::cout;
    try
    {
		//Question 1
		
		arrayWithDefaultConstructor();            // declare an array with default constructor
		orderedArrayWithCustomConstructor();      // declare an array with custom constructor
		orderedArrayOfDoublesCustomConstructor(); // array of doubles with custom constructor
		orderedArrayOfFloatsCustomConstructor();  // array of floats with custom constructor
		orderedArrayOfLongsCustomConstructor();   // array of longs with custom constructor
		compareEqualArrays();                     // two equal arrays
		compareNotEqualArrays();                  // two unequal arrays
		compareGreatThanArray();                  // array1 is > array2
		compareLessThanArray();                   // array1 is < array2
		compareGreatThanEqualArray();             // array1 is >= array2
		compareLessThanEqualArray();              // array1 is <= array2

		//Question 2

		declareSetsOfIntegersDefaultConstructor(); // declare a set of integers with defaul constructor 
		declareSetsOfDoublesCustomConstructor();   // declare a set of doubles with custom constructor

		//Question 3
		
		leads();                                  // read leads from csv file, insert them into set and write them to CSV files

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
	return 0;
}

void arrayWithDefaultConstructor() {
	
	cout << "***********************************************************" << endl;
	cout << "  Initializing array of integers with default constructor  " << endl;
	cout << "***********************************************************" << endl;

	OrderedArray<int> array;
	cout << endl;
	cout << "The array size is: " << array.length() << endl;
	cout << "The array capacity is: " << array.capacity() << endl;
	cout << "The array grow size is: " << array.getGrowSize() << endl;
	cout << endl;
	
	array.print();
	
	cout << "\n*=========================================================*" << endl;
	cout << "Pushing integers: 5, 2, 90, 4 into array" << endl;
	array.push(5);
	array.push(2);
	array.push(90);
	array.push(4);

	cout << endl;

	array.print();

	cout << endl;
	cout << "The array size is: " << array.length() << endl;
	cout << "The array capacity is: " << array.capacity() << endl;
	cout << "The array grow size is: " << array.getGrowSize() << endl;
	cout << endl;
	cout << "Adding 7 more elements to the array: 1, 3, 7, 8, 9, 10, 11" << endl;

	array.push(1);
	array.push(3);
	array.push(7);
	array.push(8);
	array.push(9);
	array.push(10);
	array.push(11);

	array.print();

	cout << endl;
	cout << "The array size is: " << array.length() << endl;
	cout << "The array capacity is: " << array.capacity() << endl;
	cout << "The array grow size is: " << array.getGrowSize() << endl;
	cout << "The element at index 2 is: " << array.getElement(2) << endl;
	cout << "\n*=========================================================*" << endl;

	cout << "Please enter a key value in order to search the array: ";
	int elementValueInt;
	//condition if the user enters a value that is not an integer
	/*while (!(cin >> elementValueInt)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: \n";
		while (cin.get() != '\n') continue;
	}*/
	

	cin >> elementValueInt;
	if (array.search(elementValueInt) < 0) {
		cout << "The value " << elementValueInt << " is not in the array!" << endl;

	}
	else {
		cout << "The value " << elementValueInt << " is at index: " << array.search(elementValueInt) << endl;
	}
}

void orderedArrayWithCustomConstructor() {
	//Declare an array with custom constructor
	cout << "\n***********************************************************" << endl;
	cout << "   Initializing array of integers with custom constructor  " << endl;
	cout << "***********************************************************" << endl;

	OrderedArray<int> arr(1);
	cout << endl;
	cout << "The array size is: " << arr.length() << endl;
	cout << "The array capacity is: " << arr.capacity() << endl;
	cout << "The array grow size is: " << arr.getGrowSize() << endl;
	
	cout << endl;
	arr.print();
	cout << endl;

	cout << "*=========================================================*" << endl;
	cout << "Pushing integers: 6, 2, 2, 4, 13 into array" << endl;
	arr.push(6);
	arr.push(2);
	arr.push(2);
	arr.push(4);
	arr.push(13);

	cout << endl;
	arr.print();
	cout << endl;

	cout << "The array size is: " << arr.length() << endl;
	cout << "The array capacity is: " << arr.capacity() << endl;
	cout << "The array grow size is: " << arr.getGrowSize() << endl;

	arr.clear();
	cout << "\nClear the array function is called... " << endl;
	cout << "*=========================================================*" << endl;
	
	arr.print();
	cout << endl;

	cout << "The array size is: " << arr.length() << endl;
	cout << "The array capacity is: " << arr.capacity() << endl;
	cout << "The array grow size is: " << arr.getGrowSize() << endl;

	cout << endl;
	cout << "*=========================================================*" << endl;
	cout << "Adding 4 more elements to the array: 2, 4, 1, 3" << endl;

	arr.push(2);
	arr.push(4);
	arr.push(1);
	arr.push(3);

	arr.print();
	cout << endl;

	cout << "The element at index 3 is: " << arr.getElement(3) << endl;
	cout << "The sum of the first two elements of the array is " << arr.sumOfTwoElements();
	cout << endl;
}

void orderedArrayOfDoublesCustomConstructor(){

	cout << "\n***********************************************************" << endl;
	cout << "   Initializing array of doubles with custom constructor   " << endl;
	cout << "***********************************************************" << endl;

	OrderedArray<double> arr1(5);
	cout << endl;
	cout << "The array size is: " << arr1.length() << endl;
	cout << "The array capacity is: " << arr1.capacity() << endl;
	cout << "The array grow size is: " << arr1.getGrowSize() << endl;
	
	arr1.print();
	cout << endl;

	cout << "*=========================================================*" << endl;
	cout << "Pushing doubles: 6.4, 2.3, 2.1, 4.5, 13.2 into array" << endl;
	arr1.push(6.4);
	arr1.push(2.3);
	arr1.push(2.1);
	arr1.push(4.5);
	arr1.push(13.2);
	
	arr1.print();
	cout << endl;
	cout << "The array size is: " << arr1.length() << endl;
	cout << "The array capacity is: " << arr1.capacity() << endl;
	cout << "The array grow size is: " << arr1.getGrowSize() << endl;
	cout << "The sum of the first two elements of the array is " << arr1.sumOfTwoElements() << endl;
	cout << "The element at index 2 is: " << arr1.getElement(2) << endl;

	cout << "*=========================================================*" << endl;
	arr1.print();
	cout << "\nRemove two elements form the array at position 2 and 4:" << endl;
	cout << endl;
	
	arr1.remove(2);
	arr1.remove(4);
	arr1.print();
	cout << endl;

	cout << "The array size is: " << arr1.length() << endl;
	cout << "The array capacity is: " << arr1.capacity() << endl;
	cout << "The array grow size is: " << arr1.getGrowSize() << endl;
	
	

	cout << "*=========================================================*" << endl;
	cout << "Adding 4 more elements to the array: 34.5, 23.6, 12.7, 13.8" << endl;

	arr1.push(34.5);
	arr1.push(23.6);
	arr1.push(12.7);
	arr1.push(13.8);
	
	arr1.print();
	cout << endl;

	cout << "Removing element out of array range at possition 10..." << endl;
	try {
		arr1.remove(10);
	}
	catch (out_of_range e) {
		cout << e.what() << endl;
	}

}

void orderedArrayOfFloatsCustomConstructor() {
	cout << "\n***********************************************************" << endl;
	cout << "    Initializing array of floats with custom constructor   " << endl;
	cout << "***********************************************************" << endl;

	OrderedArray<float> arr2(5);
	cout << endl;
	cout << "The array size is: " << arr2.length() << endl;
	cout << "The array capacity is: " << arr2.capacity() << endl;
	cout << "The array grow size is: " << arr2.getGrowSize() << endl;

	arr2.print();
	cout << endl;

	cout << "*=========================================================*" << endl;
	cout<< "Pushing floats: 3.4f, 1.3f, 24.1f, 12.5f into array" << endl;
	arr2.push(3.4f);
	arr2.push(1.3f);
	arr2.push(24.1f);
	arr2.push(12.5f);

	arr2.print();
	cout << endl;

	cout << "The array size is: " << arr2.length() << endl;
	cout << "The array capacity is: " << arr2.capacity() << endl;
	cout << "The array grow size is: " << arr2.getGrowSize() << endl;
	cout << "The sum of the first two elements of the array is " << arr2.sumOfTwoElements() << endl;
	cout << "The element at index 2 is: " << arr2.getElement(2) << endl;

	cout << "*=========================================================*" << endl;
	arr2.print();
	cout << "\nRemove an element form the array at position 2" << endl;
	cout << endl;

	arr2.remove(2);
	arr2.print();

	cout << "*=========================================================*" << endl;
	cout << "\nSearch an element in the array" << endl;

	cout << "Please enter a key value in order to search the array: ";
	float elementValueFloat;
	cin >> elementValueFloat;

	if (arr2.search(elementValueFloat) < 0) {
		cout<< "The value " << elementValueFloat << " is not in the array" << endl;

	}
	else {
		cout << "The value " << elementValueFloat << " is at possition: " << arr2.search(elementValueFloat) << endl;
	}

}

void orderedArrayOfLongsCustomConstructor() {
	cout << "\n***********************************************************" << endl;
	cout << "    Initializing array of longs with custom constructor    " << endl;
	cout << "***********************************************************" << endl;

	OrderedArray<long long> arr3(5);
	cout << endl;
	cout << "The array size is: " << arr3.length() << endl;
	cout << "The array capacity is: " << arr3.capacity() << endl;
	cout << "The array grow size is: " << arr3.getGrowSize() << endl;
	
	arr3.print();
	cout << endl;

	cout << "*=========================================================*" << endl;
	cout<<"Pushing longs: 4356881007, 3234567890, 9876543210, 7234567890 into array" << endl;
	arr3.push(4356881007);
	arr3.push(3234567890);
	arr3.push(9876543210);
	arr3.push(7234567890);
	
	arr3.print();
	cout << endl;

	cout << "The array size is: " << arr3.length() << endl;
	cout << "The array capacity is: " << arr3.capacity() << endl;
	cout << "The array grow size is: " << arr3.getGrowSize() << endl;
	cout << "The sum of the first two elements of the array is " << arr3.sumOfTwoElements() << endl;
	cout << "The element at index 2 is: " << arr3.getElement(2) << endl;

	cout << "*=========================================================*" << endl;
	arr3.print();
	cout << "\nRemove an element form the array at position 0" << endl;
	cout << endl;

	arr3.remove(0);
	arr3.print();
}

void compareEqualArrays() {
	cout << "\n***********************************************************" << endl;
	cout << "                  Comparising equal arrays                 " << endl;
	cout << "***********************************************************" << endl;

	OrderedArray<float> arr1(1);
	arr1.push(3.4f);
	arr1.push(1.3f);
	arr1.push(24.1f);
	cout << "Array 1:";
	arr1.print();

	OrderedArray<float> arr2(1);
	arr2.push(3.4f);
	arr2.push(1.3f);
	arr2.push(24.1f);
	cout << "Array 2:";
	arr1.print();

	if (arr1 == arr2)
		cout << "\narr1 == arr2\n" << endl;
	else
		cout << "\narr1 NOT == arr2 \n" << endl;
}

void compareNotEqualArrays() {
	cout << "***********************************************************" << endl;
	cout << "                Comparising Not equal arrays               " << endl;
	cout << "***********************************************************" << endl;

	OrderedArray<float> arr1(1);
	arr1.push(3.4f);
	arr1.push(1.3f);
	arr1.push(24.1f);
	cout << "Array 1:";
	arr1.print();

	OrderedArray<float> arr2(1);
	arr2.push(3.4f);
	arr2.push(1.3f);
	arr2.push(24.2f);
	cout << "Array 2:";
	arr2.print();

	if (arr1 != arr2)
		cout << "\narr1 NOT == arr2 \n" << endl;
			
	else
		cout << "\narr1 == arr2\n" << endl;
}

void compareGreatThanArray() {

	cout << "***********************************************************" << endl;
	cout << "              Comparising greater than arrays              " << endl;
	cout << "***********************************************************" << endl;

	OrderedArray<double> arr1(1);
	arr1.push(3.4);
	arr1.push(1.3);
	arr1.push(24.1);
	cout<< "Array 1:";
	arr1.print();

	OrderedArray<double> arr2(1);
	arr2.push(3.4);
	arr2.push(1.3);
	arr2.push(24.2);
	cout << "Array 2:";
	arr2.print();

	if (arr1 > arr2)
		cout << "\narr1 is > than arr2\n" << endl;
	else
		cout << "\narr1 is NOT > than arr2\n" << endl;
}

void compareLessThanArray() {

	cout << "***********************************************************" << endl;
	cout << "                Comparising less than arrays               " << endl;
	cout << "***********************************************************" << endl;

	OrderedArray<int> arr1(1);
	arr1.push(3);
	arr1.push(1);
	arr1.push(24);
	arr1.push(98);
	cout<< "Array 1:";
	arr1.print();
	
	OrderedArray<int> arr2(1);
	arr2.push(3);
	arr2.push(1);
	arr2.push(24);
	arr2.push(99);
	cout << "Array 2:";
	arr2.print();

	if (arr1 < arr2)
		cout << "\narr1 is < than arr2\n" << endl;
	else
		cout << "\narr1 is NOT < than arr2\n" << endl;

	cout << "Comparising arrays with different size" << endl;
	cout << endl;

	OrderedArray<int> arrSize4(1);
	arrSize4.push(3);
	arrSize4.push(1);
	arrSize4.push(24);
	arrSize4.push(99);
	cout << "Array size: 4 elements:";
	arrSize4.print();

	OrderedArray<int> arrSize5(1);
	arrSize5.push(3);
	arrSize5.push(1);
	arrSize5.push(24);
	arrSize5.push(99);
	arrSize5.push(0);
	cout << "Array size: 5 elements:";
	arrSize5.print();

	if (arrSize4 < arrSize5)
		cout << "\narrSize4 is < arrSize5\n" << endl;
	else
		cout << "\arrSize4 is NOT < than arrSize5\n" << endl;

}

void compareGreatThanEqualArray() {

	cout << "***********************************************************" << endl;
	cout << "          Comparising greater than or equal arrays          " << endl;
	cout << "***********************************************************" << endl;

	OrderedArray<int> arr1(1);
	arr1.push(3);
	arr1.push(1);
	arr1.push(24);
	arr1.push(9);
	cout<<"Array 1:";
	arr1.print();

	OrderedArray<int> arr2(1);
	arr2.push(3);
	arr2.push(1);
	arr2.push(24);
	arr2.push(9);
	arr2.push(2);
	cout << "Array 2:";
	arr2.print();
	//arr2.push(999);
	bool isEqual = arr1 >= arr2;

	if(isEqual)
		cout << "\narr1 is >= to arr2\n" << endl;
	else
		cout << "\narr1 is NOT >= to arr2\n" << endl;
}

void compareLessThanEqualArray() {

	cout << "***********************************************************" << endl;
	cout << "           Comparising less than or equal arrays           " << endl;
	cout << "***********************************************************" << endl;

	OrderedArray<int> arr1(1);
	arr1.push(3);
	arr1.push(1);
	arr1.push(24);
	arr1.push(9);
	cout << "Array 1:";
	arr1.print();

	OrderedArray<int> arr2(1);
	arr2.push(3);
	arr2.push(1);
	arr2.push(24);
	arr2.push(9);
	arr2.push(2);
	cout << "Array 2:";
	arr2.print();
	
	bool isEqual = arr1 <= arr2;

	if (isEqual)
		cout << "\narr1 is <= to arr2\n" << endl;
	else
		cout << "\narr1 is NOT <= to arr2\n" << endl;
}

void declareSetsOfIntegersDefaultConstructor() {
	cout << "***********************************************************" << endl;
	cout << "   Initializing set of integers with default constructor   " << endl;
	cout << "***********************************************************" << endl;
	
	MySet<int> set1;
	cout << "Set 1 with grow size of: " << set1.getGrowSize() << " elements" << endl;
	set1.print();
	cout << endl;

	cout<<"Pushing integers: 9, 1, 2, 2, 2, 5 to the set: "<<endl;

	set1.push(9);
	set1.push(1);
	set1.push(2);
	set1.push(2);
	set1.push(2);
	set1.push(5);
	set1.push(11);
	
	set1.print();
	cout << endl;

	cout << endl;
	cout << "The set size is: " << set1.length() << endl;
	cout << "The set capacity is: " << set1.capacity() << endl;
	cout << "The set grow size is: " << set1.getGrowSize() << endl;
	cout << endl;

	cout << "*=========================================================*" << endl;
	cout << endl;

	MySet<int> set2;
	cout << "Set 2 with grow size of: " << set2.getGrowSize() << " elements" << endl;
	set2.print();
	cout<<"Pushing integers: 9, 1, 2, 2, 2, 4, 7, 8, 0, 3, 10 to the set: "<<endl;

	set2.push(9);
	set2.push(1);
	set2.push(2);
	set2.push(2);
	set2.push(2);
	set2.push(4);
	set2.push(7);
	set2.push(8);
	set2.push(0);
	set2.push(3);
	set2.push(10);

	set2.print();

	cout << endl;
	cout << "The set size is: " << set2.length() << endl;
	cout << "The set capacity is: " << set2.capacity() << endl;
	cout << "The set grow size is: " << set2.getGrowSize() << endl;
	cout << endl;
	
	cout << "***********************************************************" << endl;
	cout << "      Union and Intersection of two sets of integers       " << endl;
	cout << "***********************************************************" << endl;

	cout<<"Union of set1 and set2: "<<endl;

	MySet<int> unionSet = set1 | set2;
	//auto unionSet = set1 || set2;
	unionSet.print();
	cout << endl;

	cout<<"Intersection of set1 and set2: "<<endl;

	MySet<int> intersectionSet = set1 & set2;
	intersectionSet.print();
	cout << endl;

	cout << "Unique elements of set1: " << endl;
	MySet<int> uniqueSet1 = set1 - set2;
	uniqueSet1.print();
	cout << endl;

	cout << "Unique elements of set2: " << endl;
	MySet<int> uniqueSet2 = set2 - set1;
	uniqueSet2.print();
	cout << endl;
}

void declareSetsOfDoublesCustomConstructor() {
	cout << "***********************************************************" << endl;
	cout << "    Initializing set of doubles with custom constructor    " << endl;
	cout << "***********************************************************" << endl;
	
	MySet<double> set1(5);
	cout << "Set 1 with grow size of: " <<set1.getGrowSize()<<" elements"<< endl;
	set1.print();
	cout << endl;

	cout<<"Pushing doubles: 9.1, 1.2, 2.3, 2.4, 2.3, 2.3, 5.6, 11.7 to the set: "<<endl;

	set1.push(9.1);
	set1.push(1.2);
	set1.push(2.3);
	set1.push(2.4);
	set1.push(2.3);
	set1.push(2.3);
	set1.push(5.6);
	set1.push(11.7);
	set1.print();
	cout << endl;
	cout << "The set size is: " << set1.length() << endl;
	cout << "The set capacity is: " << set1.capacity() << endl;
	cout << "The set grow size is: " << set1.getGrowSize() << endl;

	cout << endl;
	cout << "*=========================================================*" << endl;
	cout << endl;

	MySet<double> set2(10);

	cout<<"Set 2 with grow size of: "<<set2.getGrowSize()<<" elements"<<endl;
	set2.print();
	cout << endl;

	cout<<"Pushing doubles: 9.1, 1.2, 2.3, 2.4, 2.3, 2.3, 5.6, 7.8, 0.9, 3.4, 10.5, 11.7, 12.7 to the set: "<<endl;

	set2.push(9.1);
	set2.push(1.2);
	set2.push(2.3);
	set2.push(2.4);
	set2.push(2.3);
	set2.push(2.3);
	set2.push(5.6);
	set2.push(7.8);
	set2.push(0.9);
	set2.push(3.4);
	set2.push(10.5);
	set2.push(11.7);
	set2.push(12.7);
	
	set2.print();

	cout << endl;
	cout << "The set size is: " << set2.length() << endl;
	cout << "The set capacity is: " << set2.capacity() << endl;
	cout << "The set grow size is: " << set2.getGrowSize() << endl;
	cout << endl;
		
	cout << "***********************************************************" << endl;
	cout << "      Union and Intersection of two sets of doubles        " << endl;
	cout << "***********************************************************" << endl;

	cout<<"Union of set1 and set2: "<<endl;

	MySet<double> unionSet = set1 | set2;
	unionSet.print();
	cout << endl;

	cout<<"Intersection of set1 and set2: "<<endl;

	MySet<double> intersectionSet = set1 & set2;
	intersectionSet.print();
	cout << endl;
}

void leads() {
	cout<<"***********************************************************"<<endl;
	cout << "\nReading john_leads.csv...\n" << endl;

	string johnLeadsFile = "C:\\leads\\johns_leads_20.csv";
	MySet<Lead> johnLeads = readLeadsFromCSV(johnLeadsFile);
	cout << "Printing john_leads.csv: \n" << endl;

	johnLeads.printLead();
	cout << endl;
	cout<<"The John leads set size is: "<<johnLeads.length()<<endl;

	cout << "***********************************************************" << endl;
	cout << "\nReading janes_leads.csv...\n" << endl;
	string janesLeadsFile = "C:\\leads\\janes_leads_20.csv";
	MySet<Lead> janesLeads = readLeadsFromCSV(janesLeadsFile);
	cout << "Printing janes_leads.csv: \n" << endl;

	janesLeads.printLead();
	cout << endl;
	cout<<"The Jane leads set size is: "<<janesLeads.length()<<endl;
	cout << endl;

	//common leqads for john and jane
	cout << "***********************************************************" << endl;
	cout << "            The common leads for John and Jane             " << endl;
	cout << "***********************************************************" << endl;

	MySet<Lead> commonSet = johnLeads | janesLeads;
	cout << "Printing common leads... \n" << endl;
	commonSet.printLead();
	cout << endl;
	cout << "The common leads for John and Jane are: " << commonSet.length() << endl;

	//write the common leads to a file
	string commonLeadsFile = "C:\\leads\\common_leads.csv";
	writeLeadsToCSV(commonSet, commonLeadsFile);
	cout<< endl;

	//duplicate leads for john and jane
	cout << "***********************************************************" << endl;
	cout << "            The duplicate leads for John and Jane          " << endl;
	cout << "***********************************************************" << endl;

	MySet<Lead> duplicateSet = johnLeads & janesLeads;
	cout << "Printing duplicates leads... \n" << endl;
	duplicateSet.printLead();
	cout << "\nThe duplicate leads for John and Jane are: " << duplicateSet.length() << endl;
	cout << endl;

	//unique leads for John
	cout << "***********************************************************" << endl;
	cout << "                 The unique leads for John                 " << endl;
	cout << "***********************************************************" << endl;

	MySet<Lead> uniqueJohn = johnLeads - janesLeads;
	cout << "Printing John`s unique leads... \n" << endl;
	uniqueJohn.printLead();
	cout << "\nThe unique leads for John are: " << uniqueJohn.length() << endl;
	cout << endl;
	//write unique leads for John
	string uniqueJohnLeadsFile = "C:\\leads\\unique_john_leads.csv";
	writeLeadsToCSV(uniqueJohn, uniqueJohnLeadsFile);
	cout << endl;

	cout << "***********************************************************" << endl;
	cout << "                 The unique leads for Jane                 " << endl;
	cout << "***********************************************************" << endl;

	MySet<Lead> uniqueJane = janesLeads - johnLeads;
	cout << "Printing Jane`s unique leads... \n" << endl;
	uniqueJane.printLead();
	cout << "\nThe unique leads for Jane are: " << uniqueJane.length() << endl;
	cout << endl;
	//write unique leads for Jane
	string uniqueJaneLeadsFile = "C:\\leads\\unique_jane_leads.csv";
	writeLeadsToCSV(uniqueJane, uniqueJaneLeadsFile);
	cout << endl;

	//statistics
	cout << "***********************************************************" << endl;
	cout << "                      Leads statistics                     " << endl;
	cout << "***********************************************************" << endl;

	cout << "The total leads for John are: " << johnLeads.length() << endl;
	cout << "The total leads for Jane are: " << janesLeads.length() << endl;
	cout << "John unique leads: " << uniqueJohn.length() << endl;
	cout << "Jane unique leads: " << uniqueJane.length() << endl;
	cout << "The duplicate leads for John and Jane are: " << duplicateSet.length() << endl;
	cout << endl;
}