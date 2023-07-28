// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "orderedArr.h"
#include "MySet.h"
#include "lead.h"
#include <fstream>



using namespace std;

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
string returnPhoneNumber(string str);
MySet<Lead> readLeadsFromCSV(string filename);
MySet<Lead> writeLeadsToCSV(MySet<Lead> leads, string filename);


int main()
{
    try
    {
		//Question 1
		// Declare an array with default constructor
		arrayWithDefaultConstructor();

		//Declare an array with custom constructor
		orderedArrayWithCustomConstructor();
	
		//Array of doubles with custom constructor
		orderedArrayOfDoublesCustomConstructor();
	
		//Array of floats with custom constructor
		orderedArrayOfFloatsCustomConstructor();

		//Array of longs with custom constructor
		orderedArrayOfLongsCustomConstructor();

		//Two equal arrays
		compareEqualArrays();

		//Two unequal arrays
		compareNotEqualArrays();

		//Array1 is > Array2
		compareGreatThanArray();

		//Array1 is < Array2
		compareLessThanArray();

		//Array1 is >= Array2
		compareGreatThanEqualArray();

		//Array1 is <= Array2
		compareLessThanEqualArray();

		//Question 2

		//Declare a set of integers with defaul constructor 
		declareSetsOfIntegersDefaultConstructor();

		//Declare a set of doubles with custom constructor
		declareSetsOfDoublesCustomConstructor();

		//Question 3
		//read a leads from csv file
		leads();

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

void arrayWithDefaultConstructor() {
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
	//int elementValueInt;
	//condition if the user enters a value that is not an integer
	/*while (!(cin >> elementValueInt)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}*/

	//cin >> elementValueInt;
	//if (array.search(elementValueInt) < 0) {
	//	cout << "The value " << elementValueInt << " is not in the array" << endl;

	//}
	//else {
	//	cout << "The value " << elementValueInt << " is at index: " << array.search(elementValueInt) << endl;
	//}

	cout << "**************************************************" << endl;
	cout << "End of default constructor" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

void orderedArrayWithCustomConstructor() {
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

void orderedArrayOfDoublesCustomConstructor(){

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

void orderedArrayOfFloatsCustomConstructor() {
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
	/*float elementValueFloat;
	cin >> elementValueFloat;

	if (arr2.search(elementValueFloat) < 0) {
		cout<< "The value " << elementValueFloat << " is not in the array" << endl;

	}
	else {
		cout << "The value " << elementValueFloat << " is at possition: " << arr2.search(elementValueFloat) << endl;
	}*/

	cout << "**************************************************" << endl;
	cout << "End of Array of floats with custom constructor" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

void orderedArrayOfLongsCustomConstructor() {
cout << "****************************************************" << endl;
	cout << "Initializing array of longs with custom constructor" << endl;
	cout << "****************************************************" << endl;

	OrderedArray<long> arr3(5);
	cout << endl;
	cout << "The array size is: " << arr3.length() << endl;
	cout << "The array capacity is: " << arr3.capacity() << endl;
	cout << "The array grow size is: " << arr3.getGrowSize() << endl;
	cout << "Printing the array: " << endl;
	cout << endl;
	arr3.print();
	cout << endl;

	cout << "*----------------------------------------------*" << endl;
	cout << "Array of longs " << endl;
	arr3.push(4356881007);
	arr3.push(1234567890);
	arr3.push(9876543210);
	arr3.push(1234567890);
	
	

	cout << endl;
	cout << "Printing the array: " << endl;
	cout << endl;

	arr3.print();
	cout << endl;

	cout << "The array size is: " << arr3.length() << endl;
	cout << "The array capacity is: " << arr3.capacity() << endl;
	cout << "The array grow size is: " << arr3.getGrowSize() << endl;
	cout << "Printing the array: " << endl;
	cout << "The sum of the first two elements of the array is " << arr3.sumOfTwoElements() << endl;
	cout << "The element at index 2 is: " << arr3.getElement(2) << endl;

	cout << "\nRemove an element form the array" << endl;

	arr3.remove(2);
	arr3.print();
}

void compareEqualArrays() {
	cout << "****************************************************" << endl;
	cout << "Comparising equal arrays" << endl;
	cout << "****************************************************" << endl;

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
		cout << "\narr1 and arr2 are equal\n" << endl;
	else
		cout << "\narr1 and arr2 are not equal\n" << endl;
}

void compareNotEqualArrays() {
	cout << "****************************************************" << endl;
	cout << "Comparising Not equal arrays" << endl;
	cout << "****************************************************" << endl;

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
		cout << "\narr1 and arr2 are not equal\n" << endl;
			
	else
		cout << "\narr1 and arr2 are equal\n" << endl;
}

void compareGreatThanArray() {

	cout << "****************************************************" << endl;
	cout << "Comparising greater than arrays" << endl;
	cout << "****************************************************" << endl;

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
		cout << "\narr1 is greater than arr2\n" << endl;
	else
		cout << "\narr1 is not greater than arr2\n" << endl;
}

void compareLessThanArray() {

	cout << "****************************************************" << endl;
	cout << "Comparising less than arrays" << endl;
	cout << "****************************************************" << endl;

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
		cout << "\narr1 is less than arr2\n" << endl;
	else
		cout << "\narr1 is not less than arr2\n" << endl;

	cout << "Comparising arrays with different size" << endl;

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
		cout << "\narrSize4 is less than arrSize5\n" << endl;
	else
		cout << "\arrSize4 is not less than arrSize5\n" << endl;

}

void compareGreatThanEqualArray() {

	cout << "****************************************************" << endl;
	cout << "Comparising greater than or equal arrays" << endl;
	cout << "****************************************************" << endl;

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
		cout << "\narr1 is greater than or equal to arr2\n" << endl;
	else
		cout << "\narr1 is not greater than or equal to arr2\n" << endl;
}

void compareLessThanEqualArray() {

	cout << "****************************************************" << endl;
	cout << "Comparising less than or equal arrays" << endl;
	cout << "****************************************************" << endl;

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
		cout << "\narr1 is less than or equal to arr2\n" << endl;
	else
		cout << "\narr1 is not less than or equal to arr2\n" << endl;
}

void declareSetsOfIntegersDefaultConstructor() {
	cout << "**********************************************************" << endl;
	cout << "Initializing set of integers with default constructor" << endl;
	cout << "**********************************************************" << endl;
	cout << "Set 1:" << endl;
	MySet<int> set1;
	set1.print();

	cout<<"Pushing integers 9, 1, 2, 2, 2, 5 to the set: "<<endl;

	set1.push(9);
	set1.push(1);
	set1.push(2);
	set1.push(2);
	set1.push(2);
	set1.push(5);
	set1.push(11);

	cout << endl;
	cout << "The set size is: " << set1.length() << endl;
	cout << "The set capacity is: " << set1.capacity() << endl;
	cout << "The set grow size is: " << set1.getGrowSize() << endl;
	cout << "Printing the set: " << endl;
	cout << endl;

	set1.print();
	cout << endl;
	cout << "*===================================================*" << endl;
	cout << endl;

	cout << "Set 2:" << endl;

	MySet<int> set2;

	cout<<"Pushing integers 9, 1, 2, 2, 2, 4, 7, 8, 0, 3, 10 to the set: "<<endl;

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

	cout << endl;
	cout << "The set size is: " << set2.length() << endl;
	cout << "The set capacity is: " << set2.capacity() << endl;
	cout << "The set grow size is: " << set2.getGrowSize() << endl;
	cout << "Printing the set: " << endl;
	cout << endl;
	
	set2.print();
	cout << endl;

	cout << "***********************************************" << endl;
	cout << "Union and Intersection of two sets of integers " << endl;
	cout << "***********************************************" << endl;

	cout<<"Union of set1 and set2: "<<endl;

	MySet<int> unionSet = set1 | set2;
	//auto unionSet = set1 || set2;
	unionSet.print();
	cout << endl;

	cout<<"Intersection of set1 and set2: "<<endl;

	MySet<int> intersectionSet = set1 & set2;
	intersectionSet.print();
	cout << endl;
}

void declareSetsOfDoublesCustomConstructor() {
	cout << "**********************************************************" << endl;
	cout << "Initializing set of doubles with custom constructor" << endl;
	cout << "**********************************************************" << endl;
	
	MySet<double> set1(5);
	cout << "Set 1 with grow size of: " <<set1.getGrowSize()<<" elements"<< endl;
	set1.print();

	cout<<"Pushing doubles 9.1,1.2,2.3,2.4,2.3,2.3,5.6 to the set: "<<endl;

	set1.push(9.1);
	set1.push(1.2);
	set1.push(2.3);
	set1.push(2.4);
	set1.push(2.3);
	set1.push(2.3);
	set1.push(5.6);
	set1.push(11.7);
	cout << endl;
	cout << "The set size is: " << set1.length() << endl;
	cout << "The set capacity is: " << set1.capacity() << endl;
	cout << "The set grow size is: " << set1.getGrowSize() << endl;
	cout << "Printing the set: " << endl;
	cout << endl;

	set1.print();
	cout << endl;
	cout << "*===================================================*" << endl;
	cout << endl;

	MySet<double> set2(10);

	cout<<"Set 2 with grow size of: "<<set2.getGrowSize()<<" elements"<<endl;
	set2.print();

	cout<<"Pushing doubles 9.1, 1.2, 2.3, 2.4, 2.3, 2.3, 5.6, 7.8, 0.9, 3.4, 10.5 to the set: "<<endl;

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

	cout << endl;
	cout << "The set size is: " << set2.length() << endl;
	cout << "The set capacity is: " << set2.capacity() << endl;
	cout << "The set grow size is: " << set2.getGrowSize() << endl;
	cout << "Printing the set: " << endl;
	cout << endl;
		
	set2.print();
	cout << endl;

	cout << "***********************************************" << endl;
	cout << "Union and Intersection of two sets of integers " << endl;
	cout << "***********************************************" << endl;

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
	cout<<"**********************************************************"<<endl;
	cout << "\nReading john_leads.csv...\n" << endl;

	string johnLeadsFile = "C:\\Users\\teomeo\\Desktop\\leads\\johns_leads_20.csv";
	MySet<Lead> johnLeads = readLeadsFromCSV(johnLeadsFile);
	cout << "Printing john_leads.csv: \n" << endl;

	johnLeads.printLead();
	cout << endl;
	cout<<"The John leads set size is: "<<johnLeads.length()<<endl;

	cout << "**********************************************************" << endl;
	cout << "\nReading janes_leads.csv...\n" << endl;
	string janesLeadsFile = "C:\\Users\\teomeo\\Desktop\\leads\\janes_leads_20.csv";
	MySet<Lead> janesLeads = readLeadsFromCSV(janesLeadsFile);
	cout << "Printing janes_leads.csv: \n" << endl;

	janesLeads.printLead();
	cout << endl;
	cout<<"The Jane leads set size is: "<<janesLeads.length()<<endl;
	cout << endl;
	cout << "***********************************************" << endl;
	cout << "The common leads for John and Jane " << endl;
	cout << "***********************************************" << endl;

	MySet<Lead> commonSet = johnLeads | janesLeads;
	commonSet.printLead();
	cout << endl;
	
	cout << endl;

	//write the common leads to a file
	string commonLeadsFile = "C:\\Users\\teomeo\\Desktop\\leads\\common_leads.csv";
	//MySet<Lead> commonLeads = writeLeadsToCSV(commonSet, commonLeadsFile);

	ofstream outputfile;
	outputfile.open(commonLeadsFile/*, ios_base::app*/);
	outputfile << "ID" << "," << "Lead" << endl;
	for (int i = 0; i < commonSet.length(); i++) {
		outputfile << "ID " << commonSet.getElement(i).getPhoneAsId() << ", " << "Lead " << commonSet.getElement(i).getLeadDetails() << endl;
	}
	outputfile.close();
	
	cout<<"The common leads for John and Jane are: "<< commonSet.length()<<endl;
	cout<< endl;
	

}
//write the leads to the csv file
//MySet<Lead> writeLeadsToCSV(MySet<Lead> commonSet, string commonLeadsFile) {
//	ofstream outputfile;
//	outputfile.open(commonLeadsFile/*, ios_base::app*/);
//	outputfile << "ID" << "," << "Lead" << endl;
//	for (int i = 0; i < commonSet.length(); i++) {
//		outputfile << "ID " << commonSet.getElement(i).getPhoneAsId() << ", " << "Lead " << commonSet.getElement(i).getLeadDetails() << endl;
//	}
//	outputfile.close();
//	return commonSet;
//}

//read the leads from the csv file
MySet<Lead> readLeadsFromCSV(string filename) {
	MySet<Lead> leads;
	ifstream inputfile;
	if (inputfile.fail()) {
		cout << "Error opening file" << endl;
		exit(1);
	}
	inputfile.open(filename);
	string line = "";
	while (getline(inputfile, line)) {
		string lead;
		string phoneStr;
		stringstream inputString(line);
		int lastCommaPos = line.rfind(",");
		lead = line.substr(0, lastCommaPos);

		//getline(inputString, lead, '(');
		//convert the string to long
		long phoneNumber = stol(phoneStr = returnPhoneNumber(line));
		Lead newLead(lead, phoneNumber);
		//cout << newLead.toString() << endl;
		leads.pushLead(newLead);
		//cout << "L: " << lead << " P: " << phoneNumber << endl;
	}

	inputfile.close();
	return leads;
}
//return the phone number as a string
string returnPhoneNumber(string str) {

	//trace string form behind and extract the numbers
	string numericString = "";
	int delimeter = str.find_last_of("(");

	string prefixAndNumber = str.substr(delimeter);
	//cout <<"phone: "<< prefixAndNumber << endl;
	numericString = prefixAndNumber.substr(1, 3) + prefixAndNumber.substr(5);
	//cout << "prefixAndNumber: " << numericString << endl;
	numericString.erase(3, 2);
	//cout << numericString << endl;
	return numericString;

}



